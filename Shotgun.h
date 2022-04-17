#include "Weapon.h"

class Shotgun : public Weapon{
public :
    void shoot(int bullet) {
        cout << "Im shooting shotgun";
    }
   void reload(int bullet) {
        cout<<"Iam reloadin shotgun";
    }
};
