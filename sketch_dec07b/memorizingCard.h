#ifndef memorizingCard
class memorizingCard{
 private:
  char board [16] = {
   'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};

public:
  memorizingCard(){
  }
  void Shuffle ()
  {

     srand(time(NULL));
      for(int i=0;i<16;i++) //shuffle cards 20 times
    {
       int j=i+rand() % (16-i); //each time a card is assigned,
      // swap cards
       char tmp=board[i];
       board[i]=board[j];
       board[j]=tmp;
    }
}


};
#endif
