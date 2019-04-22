#ifndef ADM
class Singleton;
class SingletonDestroyer
{
  private:
    Singleton* instance;
  public:
    ~SingletonDestroyer();
    void initialize( Singleton* p );
};

class Singleton {

   private:

   friend class SingletonDestroyer;
   Singleton( const Singleton& );
   Singleton& operator=( Singleton& );
   static Singleton* instance;
   static SingletonDestroyer destroyer;
    char* name;
    char* razmer;
    char* cvet;
    char* svoystva;
    char* mifolog;
    char* opisaniye;
    char* sposobatak;
    char buffer[50];
    int tail,wings,legs,flag;
    int clegs=0;
    Singleton();
     ~Singleton();

   public:

   static Singleton* getInstance();
   void getcreature();

   void fenix();

     void reincornate(int f, char *nm);

     void show();



};
#endif
