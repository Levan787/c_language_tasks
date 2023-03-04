#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct {
  int day;
  int month;
  int year;
  char note[255];
} Note;


int calculateDayPosition(int d, int m, int y){ //position of day in week form 1 to 7
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

char *dayName(int day){ // find the name of day based on its position
  if(day == 0)
    return("Sunday");
  else if(day == 1)
    return("Monday");
  else if(day == 2)
    return("Tuesday");
  else if(day == 3)
    return("Wednesday");
  else if(day == 4)
    return("Thursday");
  else if(day == 5)
    return("Friday");
  else if(day == 6)
    return("Saturday");
  else
    return("Error: Invalid Argument Passed");
}

int isLeapYear(int year){
    if((year%4 == 0 || year%400 == 0) && year%100 != 0)
        return 1;
    return 0;
}

void findTheDay(){
    int day,month,year;
    system("cls");
    printf("Enter date with format(day month year): ");
    scanf("%d %d %d",&day,&month,&year);
    printf("Day name is : %s\n",dayName(calculateDayPosition(day,month,year)));

    FILE * data = fopen("data.bin","rb");
    Note tempNote;
    puts("Notes:");
    while(fread(&tempNote,sizeof(Note),1,data)){
            if(tempNote.day == day && tempNote.month == month && tempNote.year == year){
                puts(tempNote.note);
            }
        }

    printf("Press any key to return to menu");
    getch();
    fclose(data);
}

void printCalendar(){
    int year,month;
    int firstDay;  //position of first day in week
    int numNote = 0;
    printf("Enter month and year: ");
    scanf("%d %d",&month,&year);

    Note tempNote;
    Note notes[31];
    FILE * data = fopen("data.bin","rb");

    int monthDays[] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};

    char days[] = {" Su  Mo  Tu  We  Th  Fr  St"};

    firstDay = calculateDayPosition(1,month,year);

    printf("%s\n",days);
    for(int i=0;i<firstDay;i++)
        printf("    ");
    for(int d=1;d<=monthDays[month];d++){
        int printDay = 1;
        rewind(data);
        while(fread(&tempNote,sizeof(Note),1,data)){
            if(tempNote.day == d && tempNote.month == month && tempNote.year == year){
                printf("|%2d|",d);
                notes[numNote] = tempNote;
                numNote++;
                printDay = 0;
            }
        }
        if(printDay)
            printf(" %2d ",d);
        if((firstDay+d)%7 == 0)
            printf("\n");
    }

    if(numNote > 0){
        printf("\nThere are %d notes\n",numNote);
        printf("Press d to display or any other key to return to menu\n");
        char option = getch();
        if(option == 'd')
            for(int i=0;i<numNote;i++)
                printf("%s\n",notes[i].note);
    }
    puts("Press any key to return to menu");
    getch();
    fclose(data);
}

void addNote(){

    FILE * data;
    data = fopen("data.bin","ab");

    Note note;
    printf("Enter date of note(day month year): ");
    scanf("%d %d %d",&note.day,&note.month,&note.year);

    printf("Note: ");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    fgets(note.note,255,stdin);
    fwrite(&note,sizeof(note),1,data);
    fclose(data);
}

int main(int argc, char* argv[]){
    char option;

    FILE * data;
    if(!(data = fopen("data.bin","r")))
        fopen("data.bin","w");
    fclose(data);

    while(1){
        system("cls");
		printf("    MENU    \n");
		printf("1. Find the day\n");
		printf("2. Print calendar\n");
		printf("3. Add Note\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
        scanf(" %c",&option);

        switch(option){
        case '1':
            findTheDay();
            break;
        case '2':
            printCalendar();
            break;
        case '3':
            addNote(data);
            break;
        case '4':
            return 0;
            break;
        default:
            printf("Enter option from menu\n");
        }
    }
    return 0;
}
