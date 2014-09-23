#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * strcat_ex(char **dest, int *n, const char *src)
{
	// if(strlen(src)==0)
	// return *dest; // If src is "\0", then we dont want to actually update destination, so we return it just as it was
	int len_dest;
	if(*dest == NULL)
	{
		len_dest = 0;
		*n = 0;
	}

	else
		len_dest = strlen(*dest);

	if(*n < 1+2*(len_dest+strlen(src)))
	{
		char *buffer = malloc(1+2*(len_dest+strlen(src)));
		buffer[0] = '\0';       // makes sure strcat can work
		*n = 1+2*(len_dest+strlen(src));

		if(len_dest!=0 && sizeof(dest)!=0)
			strcpy(buffer,*dest);

		if(*dest != NULL)
			free(*dest);
		*dest = buffer;

		if(strlen(src)==0)      // moved above shit below
			return *dest;// above shit is the big comment block

		strcat(*dest,src);
		return *dest;
	}

	else
	{
		if(strlen(src)==0)
			return *dest;
		strcat(*dest, src);
		return *dest;
	}
}
char **explode(const char *str, const char *delims, int *arrlen)
{
	*arrlen = 1;    // set to 1 as there is atleast 1 str to return
	if(strlen(str)==0)      // to deal with str = ""
	{
		char **str2d = malloc( (*arrlen) * sizeof(char*));
		str2d[0] = malloc(sizeof(char*));
		str2d[0][0] = '\0';
		return str2d;
	}
	// code below is to find no of delimiters in str
	int i = 0;
	int flag = 0, j = 0;
	for(i = 0; str[i]!='\0'; ++i)
	{
		flag = 0;
		for(j = 0; delims[j]!='\0'; ++j)
		{
			if(str[i] == delims[j])
				flag = 1;
		}
		if(flag == 1)
			++(*arrlen);
	}
	// code till here basically find no of delimiters in str
	char **str2d = malloc( (*arrlen) * sizeof(char*));
	char *temp = malloc(75*sizeof(char));
	int k = 0;      // counter for *temp array
	int m = 0; // counter for **str2d array
	for(i = 0; str[i]!='\0'; ++i)
	{
		if(flag == 1)
			k=0;
		flag = 0;
		for(j = 0; delims[j]!='\0'; ++j)
		{
			if(str[i] == delims[j])
				flag = 1;
		}
		if(flag == 0)
		{
			temp[k++] = str[i];
		}
		else
		{
			temp[k] = '\0';
			str2d[m] = malloc((1+strlen(temp))*sizeof(char));
			str2d[m][0] = '\0';
			strcpy(str2d[m], temp);
			temp[0] = '\0';// This way temp is emptied
			++m;
		}
	}
	if(m!=*arrlen)
	{
		temp[k] = '\0';
		str2d[m] = malloc((1+strlen(temp))*sizeof(char));
		str2d[m][0] = '\0';
		strcpy(str2d[m], temp);
		++m;
	}
	free(temp);
	return str2d;
}
char *implode(char **strArr, int len, const char *glue)
{
	int length=0;
	int i = 0;
	for(i=0; i<len; ++i)
	{
		length+= strlen(strArr[i]);
		length+=strlen(glue);
	}
	if(length==0)   // otherwise we will malloc size 0
		++length;
	char *ret_str = malloc(length*sizeof(char));
	ret_str[0] = '\0';
	strcpy(ret_str,strArr[0]);
	for(i = 1; i < len; ++i)
	{
		int n = 0;
		strcat_ex(&ret_str, &n,glue);   // changes strcat to strcat_ex
		strcat_ex(&ret_str, &n,strArr[i]);      // same here
	}
	return ret_str;
}
int cmp_sSA(const void *a, const void *b)
{
	const char * const * a1 = (const char **) a;
	const char * const * b1 = (const char **) b;
	return strcmp(*a1,*b1);
}

void sortStringArray(char **arrString, int len)
{
	/* int i,j;
for(i = 0; i < len; ++i)
{
for(j = 0; j < len-1; ++j)
{
if(strcmp(arrString[j],arrString[j+1])>0)
{
char *temp = malloc(sizeof(char)*20);
strcpy(temp, arrString[j]);
strcpy(arrString[j], arrString[j+1]);
strcpy(arrString[j+1], temp);
free(temp);
}
}
}
	 */
qsort(arrString, len, sizeof(char *), cmp_sSA);
}

int cmp_sSC(const void *a, const void *b)
{
	const char *a1 = (const char*) a;
	const char *b1 = (const char*) b;
	if(*a1 < *b1)
		return -1;
	else if(*a1 > *b1)
		return 1;
	return 0;
}
void sortStringCharacters(char *str)
{
	// qsort(str, strlen(str), sizeof(char), (int)(*cmp)(const void *, const void *));
	qsort(str, strlen(str), sizeof(char), cmp_sSC);
}
void destroyStringArray(char * * strArr, int len)
{
	int i = 0;
	for(i = 0; i < len; ++i)
	{
		free(strArr[i]);
	}
	free(strArr);
}

