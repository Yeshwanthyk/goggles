#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>


typedef struct _tag
{
	char tname[100];
	int count;
}tag;

typedef struct _taglist
{
	tag t;
	struct _taglist  *next;
}tagList;

tagList *tgHead = NULL;

void addTag(char *tags);
void insertTag(char *tag);
int printTags(int max);
void sortTags();
int getlineno(int);

int main(int argc,char *argv[])
{
	FILE *fp;
	char tags[2048];
	int line_no=0,img_no;

	if(argc < 3)
		printf("USAGE : getTags <top_n_tags> <input_image_count>\n");
	
	else
	{
		
		int n=atoi(argv[2]);

		int inputInd[n];
		int mapInd[n];
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&inputInd[i]);	
			mapInd[i] = getlineno(inputInd[i]);
		}
		

		int index=1,match=0;
	
		fp  = fopen("tags.txt","r");
		if(!fp)
		{
			perror("FILE ERROR : ");
			exit(-1);
		}	
		while(!feof(fp))
		{
			memset(tags,0,sizeof(tags));
			fgets(tags,2048,fp);
			index = 0;	
			match=0;
			while(index<n)
			{
				if(line_no==mapInd[index])
				{
					match = 1;
					printf("LINE : %d : %d :",line_no,inputInd[index]);
					break;
				}
				index++;
			}
			if(match)
				addTag(tags);
			line_no++;
		}	
		sortTags();
		printTags(atoi(argv[1]));
	}

}

void addTag(char *tags)
{
	char *tag;

	printf("%s\n",tags);
	tag = strtok(tags," ");

	tag = strtok(NULL," ");
	
	while(tag!=NULL)
	{
		//printf("TAG : %s \t",tag);
		if(tag)
			insertTag(tag);
		tag = strtok(NULL," ");
	}
	printf("\n\n");
 
}

void insertTag(char *tag)
{

	tagList *new_tag;

	tagList *thead;
	
	thead = tgHead;
	
	int done = 0;

	char *tmp = (char *)malloc(strlen(tag));

	strcpy(tmp,tag);
	int i;

	for(i=0;i<strlen(tmp);i++)
	{
		if(tmp[i]=='\n')
			tmp[i] = '\0';
	}
	if(strlen(tmp)>=3)
	{

	while(thead!=NULL)
	{
		if(strcmp(thead->t.tname,tmp)==0)
		{
			done  = 1;
			thead->t.count++;
			////printf("%s \t %d\n",thead->t.tname,thead->t.count);
			break;
		}
		thead = thead->next;
	}

	if(!done)
	{

	new_tag = (tagList *)malloc(sizeof(tagList));
		
	if(!new_tag)
	{
		perror("MALLOC ERROR ");
	}

	memset(new_tag,0,sizeof(tagList));

	strcpy(new_tag->t.tname,tmp);
	
	new_tag->t.count = 1;
		
	new_tag->next = tgHead;

	tgHead = new_tag;

	////printf("%s \t %d\n",tgHead->t.tname,tgHead->t.count);
	
	}
	}

}

int printTags(int max)
{
	tagList *thead;

	thead = tgHead;

	int count =0;

	//printf("PRINTING TOP %d TAGS \n",max);

	while(thead!=NULL)
	{
		printf("%s",thead->t.tname,thead->t.count);
		thead = thead->next;
		count++;
		if(count == max )
			break;
		else
			printf(", ");
	}
	printf("\n");
}

void sortTags()
{

	tagList *thead;
	tagList *thead2;
	tag tmp;

	thead = tgHead;
	int count=0;
	while(thead!=NULL)
	{
		thead2 = thead->next;
		while(thead2!=NULL)
		{
			if(thead->t.count < thead2->t.count)
			{
				memset(&tmp,0,sizeof(tmp));

				memcpy(&tmp,&thead2->t,sizeof(tag));
				
				memcpy(&thead2->t,&thead->t,sizeof(tag));

				memcpy(&thead->t,&tmp,sizeof(tag));
					
			}
			thead2  = thead2->next;
	
		}
		thead = thead->next;
		count++;

	}
	//printf("TOTAL TAGS FOUND : %d\n",count);
}

int getlineno(int line)
{
	FILE *fp;
	fp = fopen("image_map","r");

	int org_line_no = 1,posn=-1;
	char buff[1024];
	int new_line=0;

	while(!feof(fp))
	{
		memset(buff,0,1024);
		fgets(buff,1024,fp);

		new_line = atoi(buff);

		if(org_line_no == line)
		{
				posn = new_line;
				break;
		}
		org_line_no++;

	}
	fclose(fp);
	return posn;
}

