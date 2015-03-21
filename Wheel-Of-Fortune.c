#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int number_of_correct_predictions=0;
int player_score=250;
int wheel_position;

void player_choice(){
    char player_input;
    printf("Please Input Your Choise: \n");
    scanf("%s",&player_input);
    if(player_input=='c' || player_input=='C'|| player_input=='s' || player_input=='S'){
        if(player_input=='c' || player_input=='C'){
            printf("GAME LAUNCHED... \n");
            game_play();
        }
        if(player_input=='s' || player_input=='S'){
            return exit(0);
        }
    }
    else{
        while(player_input!='c'|| player_input!='C'|| player_input!='s' || player_input!='S'){
            printf("Entered Character Not Valid! \n");
            scanf("%s",&player_input);
            game_play();
        }
    }
}

void game_playing(){                                                                // comparison with the number generated away from the user prediction
    int counter,generated,prediction;
    for(counter=0;counter<4;counter++){
        generated=number_generator();
        prediction=prediction_input();
        if(generated==prediction){
            number_of_correct_predictions++;
        }
    }
    printf("Number Of Correct Predictions: %d \n",number_of_correct_predictions);
}

int game_play(){
    turn_the_wheel();                                                                            //After game start, operating according to the wheel
    switch(wheel_position){
        case 1:
            printf("Earn 50 Points For At Least 1 Found The Right Prediction! \n");
            game_playing();
            if(number_of_correct_predictions >= 1){                              //Add 50 Point to Player Score
                player_score=player_score+50;
                printf("Player Score: %d \n",player_score);
                wheel_position=0;
                number_of_correct_predictions=0;
                player_choice();
            }
            else
                printf("Player Score: %d \n",player_score);
        break;
        case 2:
            printf("Earn 100 Points For At Least 1 Found The Right Prediction!\n");
            game_playing();
            if(number_of_correct_predictions >= 2){                               //Add 100 Point to Player Score
                player_score=player_score+100;
                printf("Player Score: %d \n",player_score);
                wheel_position=0;
                number_of_correct_predictions=0;
                player_choice();
            }
            else
                printf("Player Score: %d \n",player_score);
        break;
        case 3:
            printf("Earn 250 Points For At Least 1 Found The Right Prediction! \n");
            game_playing();
            if(number_of_correct_predictions >= 3){                                 //Add 250 Point to Player Score
                player_score=player_score+250;
                printf("Player Score: %d \n",player_score);
                wheel_position=0;
                number_of_correct_predictions=0;
                player_choice();
            }
            else
                printf("Player Score: %d \n",player_score);
        break;
        case 4:
            printf("Unfortunately FAILURE! \n");                                     //Failure
            wheel_position=0;
            player_score=0;
            printf("Player Score %d \n",player_score);
            break;
        case 5:
            printf("You Have Passed This Turn! \n");                                //Pass
            wheel_position=0;
            player_choice();
        break;
        case 6:
            player_score=player_score-(player_score*(0.25));                        //Reducition Score
            printf("Score Reduction Was Applied... \n");
            printf("Player Score: %d \n",player_score);
            wheel_position=0;
            player_choice();
            break;
        }
        if (player_score==0){
        return 0;
        }

}

int turn_the_wheel(){
    srand(time(NULL));
    wheel_position=1+rand()%6;
    printf("Wheel Position: %d \n",wheel_position);                    // Control for wheel positions
}

int number_generator(){
    int generated_number;
    srand(time(NULL));
    generated_number=1+rand()%10;
    printf("Generated Number= %d \n",generated_number);                // Control for generated  number
    return generated_number;
}

int prediction_input(){
    int player_prediction;
    printf("Please Input Your Prediction: ");
    scanf("%d",&player_prediction);
    if(player_prediction<1 || player_prediction>10){
        printf("Your Input's Out Of Range, Please \n");
        return prediction_input();
    }
    return player_prediction;
}

int main()
{
    srand(time(NULL));
    printf("...Welcome to Wheel Of Fortune GAME... \n");
    printf("Please Input For Start Game c/C or Terminate to Game s/S \n");
    while(player_score!=0){
        player_choice();
        if(player_score==0){
            return 0;
        }
    }
    return 0;
}
