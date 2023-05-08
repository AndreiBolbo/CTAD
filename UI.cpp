//
// Created by MSI on 23/05/2022.
//
#include "time.h"
#include "UI.h"

#include <utility>
UI::UI(Service &s) :s(s){
}

void UI::displayMenu_1() {
    cout<<"1.adauga prieten"<<endl;
    cout<<"2.afiseaza prietenii mei"<<endl;
    cout<<"3. sterge prieten"<<endl;
    cout<<"4. modifica contul"<<endl;
    cout<<"5. trimite mesaj"<<endl;
    cout<<"6. intra in conversatie "<<endl;
    cout<<"7. anulare trimitere mesaj"<<endl;
    cout<<"8. evenimente aproape de mine:"<<endl;
    cout<<"9. stergere cont."<<endl;
    cout<<"0. iesire"<<endl;

}

void UI::show_users() {
    Vector<User> users = s.get_all_users();
    for(int i=0;i<users.size();i++)
        cout<<users[i]<<endl;
}

void UI::show_friends(int id_1) {
    Vector<Friend> friends = s.get_all_friends();
    for(int i=0;i<friends.size();i++)
    {
        if(friends[i].get_id1()==id_1)
            cout<<s.show_user_by_id(friends[i].get_id2())<<endl;
        if(friends[i].get_id2()==id_1)
            cout<<s.show_user_by_id(friends[i].get_id1())<<endl;
    }
}
void UI::add_friend(int id1, int id2) {
    s.add_friend(id1,id2);
}

void UI::del_friend(int id1, int id2) {
    s.del_friend(id1,id2);
}

void UI::update_user(int id, char *nume, char *oras, int varsta) {
    s.update_user(id,nume,oras,varsta);
}

void UI::add_mesage(int id1, int id2, string text, time_t tt) {
    s.add_mesage(id1,id2,std::move(text),tt);
}

void UI::show_events() {
    Vector<Event> events = s.get_all_events();
    for(int i=0;i<events.size();i++)
        cout<<"id: "<<events[i].get_id()<<" descriere:"<<events[i].get_details()<<endl;
}
void UI::show_mesages(int id_1, int id_2) {
    vector<Mesaj> mesaje = s.get_all_mesaje();
    for(int i=0;i<mesaje.size();i++)
        if(mesaje[i].get_id1() == id_1 &&mesaje[i].get_id2() == id_2)
            cout<<s.show_user_by_id(id_1).getNume()<<":"<<mesaje[i].get_text()<<endl;
        else  if(mesaje[i].get_id2() == id_1 &&mesaje[i].get_id1() == id_2)
            cout<<s.show_user_by_id(id_2).getNume()<<":"<<mesaje[i].get_text()<<endl;
}

void UI::del_mesage(int id1, int id2, string text, time_t tt) {
    s.del_mesage(id1,id2,text,tt);
}

void UI::del_user(int id, char *nume, char *oras, int varsta) {
    s.del_user(id,nume,oras,varsta);
}

void UI::add_user(int id, char *nume, char *oras, int varsta) {
    s.add_user(id,nume,oras,varsta);
}

void UI::add_event(int id, string details) {
    s.add_event(id,details);
}
void UI::run_menu() {
    while(true)
    {
        cout<<"1.login"<<endl;
        cout<<"2.creaza cont"<<endl;
        cout<<"3. creeaza eveniment"<<endl;
        cout<<"0. iesire"<<endl;
        int op;
        cin>>op;
        if(op==1)
        {
            cout<<"Dati id_ul contului:"<<endl;
            int id;
            cin>>id;
            if(s.read_user_by_id(id))
            {

                while (true)
                {
                    cout<<"bine ati venit, contul:"<<s.show_user_by_id(id)<<endl;
                    displayMenu_1();
                    int opt;
                    cin>>opt;
                    if(opt==1)
                    {
                        try{
                            show_users();
                            int id_2;
                            cout<<"id_ul user_ului pe care vreti sa il adaugati:";
                            cin>>id_2;
                            add_friend(id, id_2);
                        }
                        catch (invalid_argument &e)
                        {
                            cout<<e.what()<<endl;
                        }
                    }
                    else if(opt == 2)
                    {
                        show_friends(id);
                    }
                    if(opt == 3)
                    {
                        cout<<"scrieti id_ul prietenului pe care doriti sa stergeti:"<<endl;
                        int id_3;
                        cin>>id_3;
                        del_friend(id,id_3);
                    }
                    if(opt == 4)
                    {
                        cout<<"schimba numele:";
                        char *nume = new char[10];
                        cin>>nume;
                        cout<<endl<<"schimba orasul:";
                        char *oras = new char[10];
                        cin>>oras;
                        int varsta;
                        cout<<endl<<"schimba varsta: ";
                        cin>>varsta;
                        update_user(id,nume,oras,varsta);
                    }
                    if(opt==5)
                    {
                        try{
                            show_users();
                            int id_5;
                            cout<<"id_ul user_ului la care vreti sa i scrieti:";
                            cin>>id_5;
                          //  cout<<endl;
                            cout<<"scrieti:"<<endl;
                            string text;
                            //scanf(, text);
                            cin.sync();
                              getline(cin,text);
                           // cin>>text;
                            time_t tt = time(nullptr);
                            add_mesage(id, id_5,text,tt);
                        }
                        catch (invalid_argument &e)
                        {
                            cout<<e.what()<<endl;
                        }


                    }
                    if(opt==6)
                    {
                        show_users();
                        int id_6;
                        cout<<"mesajele cu user-ul cu id_ul:";
                        cin>>id_6;
                        cout<<endl;
                        show_mesages(id,id_6);
                    }
                    if(opt==7)
                    {
                        show_users();
                        int id_6;
                        cout<<"mesajele cu user-ul cu id_ul:";
                        cin>>id_6;
                        time_t tt = time(nullptr);
                        cout<<endl;
                        show_mesages(id,id_6);
                        cout<<"mesajul pe care vreti sa il stergeti:";
                        string text;
                        //scanf(, text);
                        cin.sync();
                        getline(cin,text);
                        Mesaj m;
                        m = s.read_mesage_by_id(id,id_6,text);
                        del_mesage(m.get_id1(),m.get_id2(),m.get_text(),m.get_time());
                    }
                    if(opt == 8)
                    {
                        if(s.get_all_events().size())
                        {
                            show_events();
                            cout<<"daca doriti sa luati parte la un event scrieti id_ulevenimentului:";
                            int id_8;
                            cin>>id_8;
                            cout<<"participate/maybe/interested:";
                            string decision;
                            cin>>decision;
                            User u;
                            u =  s.show_user_by_id(id);
                            if(decision == "participate")
                                s.add_participant_by_id(id_8,u);
                            else if(decision== "interested")
                                s.add_interested_by_id(id_8,u);
                            else if(decision == "maybe")
                                s.add_maybe_by_id(id_8,u);
                            else
                                cout<<"cuvant incorect";
                        }
                        else cout<<"nu exista evenimente"<<endl;


                    }
                    if(opt ==9)
                    {
                        User u;
                        u = s.show_user_by_id(id);
                        del_user(u.get_id(),u.getNume(),u.getOras(),u.getVarsta());
                        break;
                    }
                    if(opt == 0)
                        break;
                }
            }
            else
            {
                cout<<"nu exista contul,doriti sa creati unul? Da/Nu";
                string yn;
                cin>>yn;
                if(yn== "Da")
                    op = 2;
                else
                    break;

            }
        }
        if(op == 2)
        {
            try {
                cout<<"dati id:";
                int id;
                cin>>id;
                cout<<"dati numele:";
                char *nume = new char[10];
                cin>>nume;
                cout<<"dati orasul :";
                char *oras = new char[10];
                cin>>oras;
                int varsta;
                cout<<"dati  varsta: ";
                cin>>varsta;
                add_user(id,nume,oras,varsta);
            }
            catch (invalid_argument &e)
            {
                cout<<e.what()<<endl;
            }
        }
        if(op==3)
        {
            try {
                cout<<"dati id-ul evenimentului:";
                int id_e;
                cin>>id_e;
                cout<<"dati descrierea evenimentului:";
                cin.sync();
                string text;

                getline(cin,text);
                add_event(id_e,text);
            }
            catch (invalid_argument &e)
            {
                cout<<e.what()<<endl;
            }

        }
        if(op == 0)
            break;
    }
}