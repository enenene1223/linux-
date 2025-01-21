#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 256

void copyFile(char* sourceFile,char* targetFile);
void deleteFile(char* fileName);
void compress(char* packageName,char* fileName);
void decompress(char* packageName);

int main()
{
	char command[MAX_COMMAND_LENGTH];
	
	printf("Welcome to the File Management System!\n");
	printf("1.Copy:cp <sourceFilePath> <targetFilePath>\n");
	printf("2.Delete:rm <filePath>\n");
	printf("3.Compress:tar -czf <packageName> <fileName>\n");
	printf("4.Decompress:tar -xzf <packageName>\n");
	printf("5.exit:Exit the program\n");
	
	while(1)
	{
    	printf("Please input command:");
        if (fgets(command,sizeof(command),stdin) == NULL) 
		{
            printf("Error reading input.\n");
            continue;
        }
        
        command[strcspn(command, "\n")] = '\0'; 
        
        char* token=strtok(command," ");
        
        if (strcmp(token,"exit") == 0) 
		{
            printf("Exiting program.\n");            
            break;
        }
	
	
	    if(strcmp(token,"cp") == 0)
	    {
	    	char* sourceFile=strtok(NULL," ");
	      	char* targetFile=strtok(NULL," ");
		  	char* extratoken=strtok(NULL," ");
	    	if (sourceFile && targetFile && extratoken == NULL)
                copyFile(sourceFile, targetFile);
            else if (sourceFile == NULL || targetFile == NULL)
                printf("Error: Invalid cp command. Usage: cp <sourceFilePath> <targetFilePath>\n");
            else
                printf("Error: Too many arguments. Usage: cp <sourceFilePath> <targetFilePath>\n");
        }

	    else if(strcmp(token,"rm") == 0)
	    {
	      	char* fileName=strtok(NULL," ");
		  	char* extratoken=strtok(NULL," ");
	      	if (fileName && extratoken == NULL)
                deleteFile(fileName);
            else if (fileName == NULL)
                printf("Error: Invalid rm command. Usage: rm <filePath>\n");
            else
                printf("Error: Too many arguments. Usage: rm <filePath>\n");
        }

	    else if(strcmp(token,"tar") == 0)
	    {
		  	char* token1=strtok(NULL," ");

		  	if(strcmp(token1,"-czf") == 0)
	      	{
	        	char* packageName=strtok(NULL," ");
	        	char* fileName=strtok(NULL," ");
				char* extratoken=strtok(NULL," ");
	        	if(packageName && fileName && extratoken == NULL)
                    compress(packageName, fileName);
                else if(packageName == NULL || fileName == NULL)
                    printf("Error: Invalid tar -czf command. Usage: tar -czf <packageName> <fileName>\n");
                else
                    printf("Error: Too many arguments. Usage: tar -czf <packageName> <fileName>\n");
		 	}
	      	else if(strcmp(token1,"-xzf") == 0)
	      	{
	        	char* packageName=strtok(NULL," ");
				char* extratoken=strtok(NULL," ");
	        	if(packageName && extratoken == NULL)
                    decompress(packageName);
                else if(packageName == NULL)
                    printf("Error: Invalid tar -xzf command. Usage: tar -xzf <packageName>\n");
                else
                    printf("Error: Too many arguments. Usage: tar -xzf <packageName>\n");
	      	}
	    	else
	        	printf("Error: Invalid tar command. Usage:'tar -czf <packageName> <fileName>' or 'tar -xzf <packageName>'\n");
	    }
		
	    else
	      	printf("Unknown command.\n");
			
    }

	return 0;
 } 
 
//    Ϊ    ʵ  
 
void copyFile(char* sourceFile,char* targetFile)
{
 	char cmd[MAX_COMMAND_LENGTH];
 	snprintf(cmd,sizeof(cmd),"cp '%s' '%s'",sourceFile,targetFile);
 	int result=system(cmd);
 	if(result != 0)
 	  printf("Error: Copy command failed to execute.\n");
 	else
 	  printf("Copy successfully.\n");
}
 
void deleteFile(char* fileName)
{
	char cmd[MAX_COMMAND_LENGTH];
 	snprintf(cmd,sizeof(cmd),"rm '%s'",fileName);
 	int result=system(cmd);
 	if(result != 0)
 	  printf("Error: Delete command failed to execute.\n");
 	else
 	  printf("Delete successfully.\n");
}

void compress(char* packageName,char* fileName)
{
	char cmd[MAX_COMMAND_LENGTH];
 	snprintf(cmd,sizeof(cmd),"tar -czf '%s' '%s'",packageName,fileName);
 	int result=system(cmd);
 	if(result != 0)
 	  printf("Error: Compress command failed to execute.\n");
 	else
 	  printf("Compress successfully.\n");
}

void decompress(char* packageName)
{
	char cmd[MAX_COMMAND_LENGTH];
 	snprintf(cmd,sizeof(cmd),"tar -xzf '%s'",packageName);
 	int result=system(cmd);
 	if(result != 0)
 	  printf("Error: Decompress command failed to execute.\n");
 	else
 	  printf("Decompress successfully.\n");
}


