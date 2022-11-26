/*
SARDAR PATEL INSTITUTE OF TECHNOLOGY
DS MINI PROJECT 
D2 Batch
Group Members:
1. 2021700022 - Anish Gade
2. 2021700023 - Aditya Gangal
3. 2021700026 - Bodhisatya Ghosh

Topic: Hangman Game

Data Structures Used: Stacks, Linked Lists, Arrays
Langauges Used: C++, C
*/



#include <iostream>
#include<stdlib.h>
#include <vector>
#include <time.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*stack1,*stack2;
string words[]={"computer","rocketscience","elonmusk","inception","spit","flutter","java","mumbai","programming","california"};
string hints[]={"A very versatile machine","The hardest science known to a layman","A very famous businessman","A movie about dreams in the dreams","A place which you love and hate","A programming language","An op programming language","A city","A skill","A famous state of USA"};
void push(struct node**top,int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=*top;
    *top=temp;
}
int pop(struct node**top)
{
    struct node *temp;
    int data;
    temp=*top;
    *top=(*top)->next;
    data=temp->data;
    free(temp);
    return data;
}
int getTop(struct node*top)
{
    return top->data;
}

void greet()
{
  cout << "=====================\n";
  cout << "Hangman: The Game\n";
  cout << "=====================\n";
  cout << "Instructions: Save your friend from being hanged by guessing the letters in the codeword.\n";
  cout<<  "              You have 6 chances to guess the correct word.\n";
  cout<<  "              If you guess the word correctly, you win.\n";
  cout<<  "              If you guess three letters correctly in a row the guy will be undrawn by one step.\n";
  cout<< "               A hint will be given for each word.\n";
}

void display_misses(int misses)
{
  if(misses==6)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==5)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==4)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<"  |   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==3)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==2)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|\\  | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==1)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|\\  | \n";
    cout<<" /    | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==0)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|\\  | \n";
    cout<<" / \\  | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }

}
void display_status(vector<char> incorrect, string answer)
{
  cout<<"Incorrect Guesses: \n";

  for(int i = 0; i<incorrect.size(); i++)
  {
    cout<<incorrect[i]<<" ";
  }

  cout<<"\nCodeword:\n";

  for(int i = 0; i<answer.length(); i++)
  {
    cout<<answer[i]<<" ";
  }
}
void end_game(string answer, string codeword)
{
  if(answer==codeword)
  {
    cout<<"Hooray! You saved the person from being hanged and earned a medal of honor!\n";
    cout<<"Congratulations!\n";
  }
  else
  {
    cout<<"On no! The man is hanged!\n";
  }
}

int main()
{
  greet();

  int randomnumber;
  srand(time(NULL));
  randomnumber = rand() % 9;

  for(int i=0;i<7;i++)
  {
    push(&stack1,i);
  }

  string codeword = words[randomnumber];
  cout<<"Hint: "<<hints[randomnumber]<<endl;
  string answer;
  for(int i = 0; i<codeword.length(); i++)
  {
    answer+="_";
  }
  
 
  vector<char> incorrect;
  bool guess = false;
  char letter;
  int misses=0;
  int hits=0;

  while(answer!=codeword && misses < 7)
  {
    display_misses(getTop(stack1));
    display_status(incorrect, answer);

    cout<<"\n\nPlease enter your guess: ";
    cin>>letter;

    for(int i = 0; i<codeword.length(); i++)
    {
      if(letter==codeword[i])
      {
        answer[i] = letter;
        guess = true;
        hits++; 
      }
    }
    if(guess)
    { if(hits==3 && getTop(stack1)!=6)
      {
        cout<<"The chances of saving your friend increase\n";
        push(&stack1,pop(&stack2));
        hits=0;
      }
      cout<<"\nCorrect!\n";
    }
    else
    {
      cout<<"\nIncorrect! Another portion of the person has been drawn.\n";
      incorrect.push_back(letter);
      misses++;
      push(&stack2,pop(&stack1));
    }
    guess = false;
  }

  end_game(answer, codeword);
  return 0;
}
