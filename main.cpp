#include <iostream>
#include "ABCNode.h"
#include "ABC.h"
#include "User.h"
#include "vector.h"
#include "Friend.h"
#include <ctime>
#include "mesaj.h"
#include "Repo.h"
#include "Set_abc.h"
#include "Service.h"
#include "UI.h"
#include "cstring"

using namespace std;
int main() {
//    ABCNode<int> node(2);
//    ABC<int> ab;
//    ab.add(7);
//    ab.add(1);
//    ab.add(3);
//    ab.add(5);
//    ab.add(9);
//    ab.add(11);
//    ab.add(8);
   Repo repo;


//    cout<<endl;
//    User u1(1,"Teodor", "Bistrita", 10);
//    ABC<User> ab;
//    User u6(6,"Teo", "Bistrita", 35);
//    User u2(2,"Teodor", "Bistrita", 30);
//    User u3(3,"Daniela", "Cluj", 24);
//    User u4(4,"Roxana", "Bacau", 40);
//    User u5(2,"Maria", "Nasaud", 20);

      Service s(repo);
      UI u(s);
      char *nume = new char[20];
      char *oras = new char[20];
      strcpy(nume , "Alex");
      strcpy(oras,"Megidia");
      u.add_user(1,nume,oras,14);
    strcpy(nume , "Vlad");
    strcpy(oras,"Cluj");
    u.add_user(2,nume,oras,15);
    strcpy(nume , "Ale");
    strcpy(oras,"Mures");
    u.add_user(3,nume,oras,17);
    strcpy(nume , "Luca");
    strcpy(oras,"Slobozia");
    u.add_user(4,nume,oras,17);
    strcpy(nume , "Paul");
    strcpy(oras,"Calugareni");
    u.add_user(5,nume,oras,18);
    strcpy(nume , "Paula");
    strcpy(oras,"Huedin");
    u.add_user(6,nume,oras,19);
    strcpy(nume , "Bogdan");
    strcpy(oras,"Ilfov");
    u.add_user(7,nume,oras,18);
    strcpy(nume , "Eliza");
    strcpy(oras,"Oradea");
    u.add_user(8,nume,oras,15);
    strcpy(nume , "Elias");
    strcpy(oras,"Ludus");
    u.add_user(9,nume,oras,15);
    strcpy(nume , "Mark");
    strcpy(oras,"Timisoara");
    u.add_user(10,nume,oras,13);
    strcpy(nume , "Marius");
    strcpy(oras,"Timisoara");
    u.add_user(11,nume,oras,17);
    strcpy(nume , "Aurel");
    strcpy(oras,"Cluj");
    u.add_user(12,nume,oras,16);
    strcpy(nume , "Cristi");
    strcpy(oras,"Brasov");
    u.add_user(13,nume,oras,13);
    strcpy(nume , "Andrei");
    strcpy(oras,"Berlin");
    u.add_user(14,nume,oras,19);
    strcpy(nume , "Iulian");
    strcpy(oras,"Dubai");
    u.add_user(15,nume,oras,22);
    u.add_friend(1,2);
    u.add_friend(1,3);
    u.add_friend(2,3);
    u.add_friend(4,5);
    u.add_friend(4,6);
    u.add_friend(5,6);
    u.add_friend(7,8);
    u.add_friend(7,9);
    u.add_friend(8,9);
    u.add_friend(9,10);
    u.add_friend(9,11);
    u.add_friend(10,11);
    u.add_friend(12,13);
    u.add_friend(12,14);
    u.add_friend(13,14);
    u.add_friend(15,1);
    u.add_friend(15,10);
    time_t t = time(nullptr);
    u.add_mesage(1,2,"salut",t-40);
    u.add_mesage(2,1, "ce faci?", t-39);
    u.add_mesage(1,3,"iesim?",t-38);
    u.add_mesage(3,1,"Hai",t-37);
    u.add_mesage(2,3,"ne uitam la meci?",t-36);
    u.add_mesage(3,2,"hai la marty",t-35);
    u.add_mesage(4,5,"cf?",t-34);
    u.add_mesage(5,4,"bn",t-33);
    u.add_mesage(4,6,"hai la fotbal",t-32);
    u.add_mesage(6,4,"la cat?", t-31);
    u.add_mesage(5,6,"iesi azi?",t-30);
    u.add_mesage(6,5,"vorbim ",t-29);
    u.add_mesage(7,8,"cati ani ai?",t-28);
    u.add_mesage(8,7,"15",t-27);
    u.add_mesage(7,9, "Buna ziua",t-26);
    u.add_mesage(9,7,"Buna ziua!",t-25);
    u.add_mesage(8,9,"ne vedem",t-24);
    u.add_mesage(9,8,"pa",t-23);
    u.add_mesage(9,10,"ai 20 de lei pe bt?",t-22);
    u.add_mesage(10,9,"nu am",t-21);
    u.add_mesage(9,11,"Mergem in Noa?",t-20);
    u.add_mesage(11,9,"Hai ca vin",t-19);
    u.add_mesage(10,11,"Mergem sa mancam?",t-18);
    u.add_mesage(11,10,"Da", t-17);
    u.add_mesage(12,13,"ce mai faci?", t-16);
    u.add_mesage(13,12,"da bine tu?", t-15);
    u.add_mesage(12,14,"te uiti la meci?",t-14);
    u.add_mesage(14,12,"Da",t-13);
    u.add_mesage(13,14, "de unde esti?",t-12);
    u.add_mesage(14,13,"Din America",t-11);
    u.add_mesage(15,1,"ce lucrezi?",t-10);
    u.add_mesage(1,15,"in it", t-9);
    u.add_mesage(15,10,"vii la noi?",t-8);
    u.add_mesage(10,15,"cred ca da", t-7);
      u.run_menu();

    return 0;

}
