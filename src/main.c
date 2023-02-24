
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

    char* article = malloc(sizeof(char) * 1024);
    char* language = malloc(sizeof(char) * 1024);

    strcpy(article, argv[1]);
    
    if (argc != 3)
    {
        strcpy(language, "eng");
    }

    else
    {
        strcpy(language, argv[2]);
    }

    printf("%s | %s\n", article, language);

    return 0;
}
