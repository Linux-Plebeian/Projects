#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>


bool GAME_OVER=false;
int SCORE, LOCATION_X=1, LOCATION_Y=1, ITEM_SIZE=8, SURVIVORS=4, COUNTDOWN_CARDS=75, DISTANCE_REMAINING_MI= 2170;
char test[5];
int EVENT_TYPE, EVENT, SHOP_TYPE;
int FOOD=1, SPARE_PARTS=2, BULLETS=0, CLEAN_WATER=1, MEDICINE=1, CLOTHES=0, OXEN=0;
int ITEM_LOSS_SELECTION=0, SUPPLY_TO_LOSE, ITEM_GAIN_SELECTION, SUPPLY_TO_GAIN;
int HOW_MUCH_MERCY=0,GAME_DIFFICULTY=0,MIN=0,HOW_HARD_SHOULD_THE_OTHER_EVENTS_BE=12; //GREATER=EASIER
char GAME_DIFFICULTY_SELECTION;
void menu(){
    printf("ENTER GAME DIFFICULTY(0-4): ");
    gets(&GAME_DIFFICULTY); 
    GAME_DIFFICULTY-=48;
    printf("SELECTED DIFFICULTY - %d\n", GAME_DIFFICULTY);
    switch(GAME_DIFFICULTY){
        case 0:
            printf("\nBABY MODE - LOSER\n");
            COUNTDOWN_CARDS=10;
            HOW_MUCH_MERCY=255;
            HOW_HARD_SHOULD_THE_OTHER_EVENTS_BE=100;
            break;
        case 1:
            printf("\nEASY MODE - SUCKER\n");
            COUNTDOWN_CARDS=50;
            HOW_MUCH_MERCY=15;
            HOW_HARD_SHOULD_THE_OTHER_EVENTS_BE=50;
            break;
        case 2:
            printf("\nDIFFICULTY - MEDIUM\n");
            COUNTDOWN_CARDS=75;
            HOW_MUCH_MERCY=8;
            HOW_HARD_SHOULD_THE_OTHER_EVENTS_BE=12;
            break;
        case 3:
            printf("\nDIFFICULTY - HARD\n");
            COUNTDOWN_CARDS=100;
            HOW_MUCH_MERCY=4;
            HOW_HARD_SHOULD_THE_OTHER_EVENTS_BE=8;
            break;
        default:
            printf("ENTERING: THE ROAD TO HELL - NO MERCY");
            COUNTDOWN_CARDS=255;
            HOW_MUCH_MERCY=1;
            HOW_HARD_SHOULD_THE_OTHER_EVENTS_BE=6;//REALLY FREAKING HARD - NO SHOPS, NO BENEFITS, ONLY A HELL OF A JOURNEY
            break;
    }


}
void duck_season(){//TODO implement hunting minigame



}

void shop_fort_town(SUPPLY_TO_GAIN){
     switch(SUPPLY_TO_GAIN){
            case 1:
                FOOD++;
                break;
            case 2:
                SPARE_PARTS++;
                break;
            case 3:
                BULLETS++;
                break;
            case 4:
                CLEAN_WATER++;
                break;
            case 6:
                CLOTHES++;
                break;
            case 5:
                MEDICINE++;
                break;
            case 7:
                OXEN++;
                break;
            default:
                printf("OUT OF RANGE - not a valid supply\n");
                break;
            }
            printf("+1 supplies\n");
            
    
}


void calamity(){ //thief, sheer cold, drought, food shortage, dead oxen, BROKEN AXEL SNAKE BITE, MEASLES, DYSENTERY //TODO implment custom wolf threat
    int CALAMITY_TYPE = rand() % 11;
    switch(CALAMITY_TYPE){
        case 1:
            printf("\nTHIEF\n");
            lose_supplies(rand() % 8);
            break;
        case 2:
            printf("\nSHEER COLD\n");
            if(CLOTHES>0){
                CLOTHES--;
                break;
            }
            else {
                printf("\nFROZE TO DEATH\n");
                SURVIVORS--;
            }
            break;
        case 3:
            printf("\nDROUGHT\n");
            if(CLEAN_WATER>0){
                CLEAN_WATER--;
                break;
            }
            else {
                printf("\nDIED OF THIRST\n");
                SURVIVORS--;
            }
            break;
        case 4:
            printf("\nFOOD SHORTAGE\n");
            if(FOOD>0){
                FOOD--;
                break;
            }
            else {
                printf("\nSTARVED TO DEATH\n");
                SURVIVORS--;
            }
            break;
        case 5:
            printf("\nDEAD OXEN\n");
            if(OXEN>0){
                OXEN--;
                break;
            }
            else {
                printf("\nCOULD NOT PROPEL CART WITH OXEN- DIED DAYS LATER\n");
                GAME_OVER=true;
            }
            break;
        case 6:
            printf("\nBROKEN CART\n");
            if(SPARE_PARTS>0){
                SPARE_PARTS--;
                break;
            }
            else {
                printf("\nCOULD NOT MOVE CART - DIED DAYS LATER\n");
                GAME_OVER=true;
            }
            break;
        case 7:
            printf("\nMEASLES\n");
            if(MEDICINE>0){
                MEDICINE--;
                break;
                
            }
            else {
                printf("\nDIED OF MEASLES\n");
                SURVIVORS--;
            }
            break;
        case 8:
            printf("\nDIED OF SNAKEBITE\n");
            SURVIVORS--;
            break;
        case 9:
            printf("\nYOU HAVE DIED OF DISENTERY\n");
            SURVIVORS--;
            break;
        case 10:
            printf("\nCHANCE FOR FOOD\n");
            if(BULLETS>0){
                BULLETS--;
                if(GAME_DIFFICULTY<4){
                    FOOD++;
                    printf("\nGAINED FOOD!\n");
                    break;}
                else{
                    printf("YOU MISSED AND HIT ONE OF YOUR PARTY MEMBERS");
                    SURVIVORS--;
                }
            }
            else{
                printf("\nN0 BULLETS - NO EXTRA FOOD\n");
            }
            break;
        default:
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.\n");
            break;
        


    }
}

void game_over(){

    if(GAME_OVER){
        SURVIVORS=0;
       }
}
void lose_supplies(SUPPLY_TO_LOSE){
    switch(SUPPLY_TO_LOSE){
        case 1:
            if(FOOD>0){
                FOOD--;
                break;
            }
            else{
                SUPPLY_TO_LOSE=2; 
            }
        case 2:
            if(SPARE_PARTS>0){
                SPARE_PARTS--;
                break;
            }
            else{
                SUPPLY_TO_LOSE=3; 
            }
        case 3:
            if(BULLETS>0){
                BULLETS--;
                break;
            }
            else{
                SUPPLY_TO_LOSE=4; 
            }
        case 4:
            if(CLEAN_WATER>0){
                CLEAN_WATER--;
                break;
            }
            else{
                SUPPLY_TO_LOSE=5; 
            }
        case 5:
            if(CLOTHES>0){
                CLOTHES--;
                break;
            }
            else{
                SUPPLY_TO_LOSE=6; 
            }
        case 6:
            if(MEDICINE>0){
                MEDICINE--;
                break;
            }
            else{
                SUPPLY_TO_LOSE=7; 
            }
        case 7:
            if(OXEN>0){
                OXEN--;
                break;
            }
            else{
                SUPPLY_TO_LOSE=8; 
            }
        case 8:
            printf("YOU ARE OUT OF SUPPLIES\n");
            break;
        default:
            printf("YOU ARE OUT OF SUPPLIES\n");
            break;

        }
        printf("-1 supplies\n");
        
}


void TERRAIN(){
    
    int RIVER;
    EVENT = rand() % (HOW_HARD_SHOULD_THE_OTHER_EVENTS_BE - MIN +1);
    switch(EVENT){
        case 1:       
            int MERCY = rand() % (HOW_MUCH_MERCY - MIN +1);
            if(MERCY > 2){
                printf("\n_/^7^/^7^/^7^/^7^/^7^/^7/\n^/^7^/^7^/^7^/^7^/^7^/^7_");
                printf("\n_/^7^/^7^/^7^/^7^/^7^/^7^/\n^7^/^7^/^7^/^7^/^7^/^7_\n");
                printf("You DROWNED \n");
                GAME_OVER=true;
                SURVIVORS=0;
                printf("RIP ALL PARTY MEMBERS");
                if(GAME_DIFFICULTY<2){
                    printf(" - ONLY YOU COULD MANAGE TO LOSE ON THIS EASY OF A DIFFICULTY - LOSER\n");
                }
                break;}
            else {break;}

        case 2:
            printf("\n_/^7^/^7^/^7^/^7^/^7^/^7^\n/^7^/^7^/^7^/^7^/^7^/^7_");
            printf("\n_/^7^/^7^/^7^/^7^/^7^/^7^\n/^7^/^7^/^7^/^7^/^7^/^7_\n");
            printf("select item to lose 1-7: \n ");
            printf("1. FOOD(%i), 2. SPARE PARTS(%i), 3. BULLETS(%i), 4. CLEAN WATER(%i), 5. MEDICINE(%i), 6. CLOTHES(%i), 7. OXEN(%i)\n",FOOD, SPARE_PARTS, BULLETS, CLEAN_WATER, MEDICINE,   CLOTHES, OXEN);   
            scanf("%d", &ITEM_LOSS_SELECTION);
            lose_supplies(ITEM_LOSS_SELECTION);
            printf("1. FOOD(%i), 2. SPARE PARTS(%i), 3. BULLETS(%i), 4. CLEAN WATER(%i), 5. MEDICINE(%i), 6. CLOTHES(%i), 7. OXEN(%i)\n",FOOD, SPARE_PARTS, BULLETS, CLEAN_WATER, MEDICINE,   CLOTHES, OXEN);
            break; 
        case 6:
            printf("\n_/^7^/^7^/^7^/^7^/^7^/^7^\n/^7^/^7^/^7^/^7^/^7^/^7_");
            printf("\n_/^7^/^7^/^7^/^7^/^7^/^7^/\n^7^/^7^/^7^/^7^/^7^/^7_\n"); 
            printf("\nSafely crossed the river\n"); 
            break;
        case 4:
        printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.\n");
            calamity();
            break; 
        case 7:
            printf("\n_/^7^/^7^/^7^/^7^/^7^/^7^/^\n7^/^7^/^7^/^7^/^7^/^7_");
            printf("\n_/^7^/^7^/^7^/^7^/^7^/^7^/^7\n^/^7^/^7^/^7^/^7^/^7_\n");
            printf("\nSafely crossed the river\n"); 
            break;

        case 10:
            SHOP_TYPE = rand() % 3;
            switch(SHOP_TYPE){
                case 1:
                  printf("\nShop\n");
                  break;
                case 2:
                    printf("\nFort\n");
                    break;
                case 3:
                    printf("\nTown\n");
                    break;
            }
            printf("\nSelect 2 items: \n");
            printf("1. FOOD(%i), 2. SPARE PARTS(%i), 3. BULLETS(%i), 4. CLEAN WATER(%i), 5. MEDICINE(%i), 6. CLOTHES(%i), 7. OXEN(%i)\n",FOOD, SPARE_PARTS, BULLETS, CLEAN_WATER, MEDICINE,   CLOTHES, OXEN);
            for(int i = 0; i< 2; i++){  
               scanf("%d", &ITEM_GAIN_SELECTION);
               shop_fort_town(ITEM_GAIN_SELECTION);
                }
        case 3:
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.\n");
            break;
            calamity();
            break;
        default:
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.");
            printf("\n...,.,..,,.,.,.,.,.\n");
            break;
    }
    printf("FOOD: %i, SPARE PARTS: %i, BULLETS: %i, CLEAN WATER: %i, MEDICINE: %i, CLOTHES: %i, OXEN: %i\n",FOOD, SPARE_PARTS, BULLETS, CLEAN_WATER, MEDICINE, CLOTHES, OXEN);

}




void render(int X, int Y){
    system("clear");
    for(int LOOP_Y=0; LOOP_Y<Y;LOOP_Y++){
        printf("\n");
    }
    for(int LOOP_X=0; LOOP_X<X;LOOP_X++){
        printf(" ");
    }
    
}

//define the trailer ascii appearance and logic
void PLAYER(){
    render(LOCATION_X+1,LOCATION_Y);
    if(GAME_DIFFICULTY>1 && GAME_DIFFICULTY<4){
        printf(" ___________                         MOO     \n");
        printf("/           |____  _________(_____) /        \n");
        printf("|___________|___---|________|('_')          \n");
        printf(" oo       oo        |_ |_ |_ |_      \n");
      }
    else if(GAME_DIFFICULTY<2){
    printf("      #^#    MAMA! THE TWAIW IS TOO HAWD!\n");
    printf("    (  >_<)  /        \n");
    printf("    (   ~ )            \n");
    printf("   /|___V_|\         ______\n");
    printf("    \_____/ |       |______|\n");
    printf("    ()   ()  '-,_,-'()    ()    \n");
    }
    else if(GAME_DIFFICULTY>3){
        printf("     ___$^&*^&___                        !WHY! \n");
        printf("    /      /     |____  __//////_(_____) /        \n");
        printf("    |___ ## _____|___---|________|(@~@)        &  \n");
        printf(" &    oo       oo        | | | | |  ( )    \n");
    }
}

//execute functions here - main loop
int main(){


printf(" _____ _   _ _____    ___  ____  _____ ____  ___  _   _ \n");
printf("|_   _| | | | ____| /  _  |  _  | ____/ ___|/ _  | | | |\n");
printf("  | | | |_| |  _|   | | | | |_) |  _|| |  _| | | |  || |\n");
printf("  | | |  _  | |___  | |_| |  _ <| |__| |_| | |_| | ||  |\n");
printf(" _|_|_|_|_|_|_____| !____/|_| |_|_____|____|!___/|_| |_|\n");
printf("|_   _|  _ |    / | |_ _| |\n");
printf("  | | | |_} |  / _ | | || |\n");
printf("  | | |  _ <  /___ | | || |___\n");
printf("  |_| |_| |_|/_/ |_||___|_____|\n\n");                     

    menu();
    do{
    
    gets(test);//waits for the user to press enter
    
    srand(time(NULL));
    PLAYER();

    TERRAIN();
    LOCATION_Y++;
    printf("SURVIVORS - %d              MI LEFT - %d\n", SURVIVORS, DISTANCE_REMAINING_MI); 
    DISTANCE_REMAINING_MI-=(2170/COUNTDOWN_CARDS);
    game_over();
    if(DISTANCE_REMAINING_MI<=0){
        DISTANCE_REMAINING_MI=0;
        printf("\nYOU MADE IT ");
        if(GAME_DIFFICULTY<2){
            printf("LOSER - DO BETTER\n");
        }
        else{
            printf("\nCONGRATULATIONS\n");
            printf("YOU HAVE CONQUERED THIS DIFFICULT TRIAL OF A TRAIL\n");
        }
        return 0;
    }
    }while(!GAME_OVER);
    return 0;
}
