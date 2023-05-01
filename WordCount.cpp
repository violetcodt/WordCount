#include <stdio.h>
#include <string.h>
int main (int ac, char *av[])
{
    
    FILE *fp;
    int count = 0; 
    if ((fp=fopen(av[2], "r")) == NULL)
    {
        puts("error!\n");
        return 0;
    }
    if (av[1][1] == 'w') // 单词
    {
        char str[1024];
        while (fscanf(fp, "%s", str) != EOF)
        {
            count ++;
            for (int i = 1; i < strlen(str) - 1; i ++)
                if (str[i] == ',' && str[i - 1] != ',' && str[i + 1] != ',') {
				
                    count ++;
					}
        }
        printf("单词数=%d\n", count);
    }
    else if (av[1][1] == 'c') // 字符
    {
        char c;
        while ((c = fgetc(fp)) != EOF) {
		count ++;
		}
        printf("字符数=%d", count);
    }
    fclose(fp);
    return 0;
}


