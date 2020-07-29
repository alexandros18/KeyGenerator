#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

void scan_the_length(int *length);
void cls(void);
void fill_the_buffer(char *password, int length);
int main()
{	
	srand(time(0));

	int length;
	char *password;


	cls();
	
	scan_the_length(&length);
    	
	password=(char*)malloc(length+1);
	password[length]=0;

	fill_the_buffer(password, length);

	cls();
	
	printf("Your %d character password is:\n\n%s\n\n", length, password);
	free(password);
	printf("You have 5 seconds to copy it\n");
	sleep(5);
	cls();
	return 0;
}

void fill_the_buffer(char *password, int length)
{
  int i, random_value;
    for(i=0; i<length; i++)
    {
        sleep(0.700);
        random_value=rand()%90+33;
	if(random_value==34 || (random_value>=38 && random_value<=47) || (random_value>=58 && random_value<=63) || (random_value>=91 && random_value<=94) || random_value==96)
        {
	    i--;
	    continue;
	}
        password[i]=random_value;
    }
    return;
}

void cls(void)
{
    system("clear");  //FOR LINUX
    //system("cls");  FOR WINDWOS
    return;
}


void scan_the_length(int *length)
{
    do
    {
        printf("Give the length of the password: ");
        scanf("%d", length);
        if(*length<=0 || *length>100)
        {
	    cls();
            printf("*** password length>0 and <=100 ***\n");
            sleep(2);
            cls();
        }
    } while(*length <= 0 || *length>100);
}
