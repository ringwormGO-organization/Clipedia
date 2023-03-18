
/**
 * TODO:
 *  Small
 *      Print articles
 * Big
 *      Multiple languages
 *      Pictures
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <dirent.h>

char *shrink_string(char *str, size_t N)
{
    int len = strlen(str);

    if (len < N)
    {
        return "";
    }

    else
    {
        char *shrunk_str = (char *)malloc((len - (N - 1)) * sizeof(char));
        strncpy(shrunk_str, str, len - N);
        shrunk_str[len - N] = '\0';

        return shrunk_str;
    }
}

/**
 * Code list:
 *  0 - not enough arguments
 *  1 - article not found
 */
void error(int code)
{
    switch (code)
    {
    case 0:
        printf("Usage : ./clipedia <article> <language (eng by default)>\n");
        break;

    case 1:
        printf("Article not found!\n");
        break;

    default:
        printf("Unknown error code %d!\n", code);
        break;
    }

    printf("Exiting...\n");
    exit(0);
}

/**
 * Arguments:
 *  article_name
 *  language (eng default)
 */
int main(int argc, char const *argv[])
{

    if (argc < 2) /* [0] - program_name, [1] - article, [2] - language (optional) */
        error(0);

    char *article = malloc(sizeof(char) * 1024);
    char *language = malloc(sizeof(char) * 1024);

    strcpy(article, argv[1]);

    if (argc != 3)
    {
        strcpy(language, "eng");
    }

    else
    {
        strcpy(language, argv[2]);
    }

    /* Find article */
    /* ---- ------- */
    DIR *dir;
    struct dirent *ent;

    /* open the "texts" folder */
    dir = opendir("texts");

    if (dir != NULL)
    {
        /* loop through all files in the folder */
        while ((ent = readdir(dir)) != NULL)
        {
            char *shrunk_str = shrink_string(ent->d_name, 4);

            /* check if the file name matches the input string */
            if (strcmp(shrunk_str, article) == 0)
            {
                printf("---------- %s ---------- \n", article);

                FILE *file;
                char line[1024];

                char *filename = (char *)malloc(sizeof(char) * 1024);
                strcat(filename, "texts/");
                strcat(filename, ent->d_name);

                file = fopen(filename, "r");

                if (file == NULL)
                {
                    printf("Error opening file!\n");
                    return 1;
                }

                while (fgets(line, 1024, file) != NULL)
                {
                    if (strncmp(line, "picture: ", strlen("picture: ")) == 0)
                    {
                        printf("IMAGINE A PICTURE HERE!\n");
                    }

                    else
                    {
                        printf("%s", line);
                    }
                }

                free(filename);
                closedir(dir);

                return 0;
            }

            else if (strcmp(article, "cocaine") == 0)
            {
                printf("---------- Cocaine ---------- \n");

                FILE *file;
                char line[1024];

                char filename[50] = "texts/c17h21no4.txt";

                file = fopen(filename, "r");

                if (file == NULL)
                {
                    printf("Error opening file!\n");
                    return 1;
                }

                while (fgets(line, 1024, file) != NULL)
                {
                    if (strncmp(line, "picture: ", strlen("picture: ")) == 0)
                    {
                        printf("IMAGINE A PICTURE HERE!\n");
                    }

                    else
                    {
                        printf("%s", line);
                    }
                }

                closedir(dir);
                return 0;
            }
        }

        printf("Article not found! You can help by writing [%s] and submiting it.\n", article);
        closedir(dir);
    }

    else
    {
        printf("Error opening directory!\n");
        return 1;
    }

    return 0;
}
