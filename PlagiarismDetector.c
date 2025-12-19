#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WINDOW 30

int compare_windows(const void *a, const void *b) 
{
    return strncmp(*(const char **)a, *(const char **)b, WINDOW);
}

char *read_file(const char *name) 
{
    FILE *f = fopen(name, "r");
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    long s = ftell(f);
    rewind(f);
    char *data = malloc(s + 1);
    if (!data) return NULL;
    fread(data, 1, s, f);
    data[s] = '\0';
    fclose(f);
    return data;
}

void normalize(char *s) 
{
    int i, j = 0;
    int in_comment = 0;
    for (i = 0; s[i]; i++) 
	{
        if (!in_comment && s[i] == '/' && s[i + 1] == '/') 
		{
            in_comment = 1;
            i++;
            continue;
        }
        if (in_comment && s[i] == '\n') 
		{
            in_comment = 0;
            continue;
        }
        if (in_comment) continue;
        if (!isspace(s[i]))
		{
            s[j++] = tolower(s[i]);
        }
    }
    s[j] = '\0';
}

double compare_optimized(char *a, char *b) 
{
    int la = strlen(a), lb = strlen(b);
    if (la < WINDOW || lb < WINDOW) 
	{
		return 0;
	}

    int num_windows_b = lb - WINDOW + 1;
    char **windows_b = malloc(num_windows_b * sizeof(char *));
    if (!windows_b) 
	{
		return 0;
	}

    for (int i = 0; i < num_windows_b; i++) 
	{
        windows_b[i] = b + i;
    }

    qsort(windows_b, num_windows_b, sizeof(char *), compare_windows);

    int match = 0;
    int num_windows_a = la - WINDOW + 1;

    for (int i = 0; i < num_windows_a; i++) 
	{
        char *target = a + i;
        if (bsearch(&target, windows_b, num_windows_b, sizeof(char *), compare_windows)) 
		{
            match++;
        }
    }

    free(windows_b);

    return (2.0 * match) / (num_windows_a + num_windows_b) * 100.0;
}

int main(int argc, char *argv[]) 
{
    if (argc < 3) 
	{
        printf("Usage: %s file1.c file2.c [...]\n", argv[0]);
        return 0;
    }

    int n = argc - 1;
    char **data = malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) 
	{
        data[i] = read_file(argv[i + 1]);
        if (!data[i]) 
		{
            printf("Error reading %s\n", argv[i + 1]);
            return 1;
        }
        normalize(data[i]);
    }

    for (int i = 0; i < n; i++) 
	{
        for (int j = i + 1; j < n; j++) 
		{
            printf("Similarity between %s and %s : %.2f%%\n", argv[i + 1], argv[j + 1], compare_optimized(data[i], data[j]));
        }
    }

    for (int i = 0; i < n; i++)
	{
		free(data[i]);
	}
    free(data);

    return 0;
}