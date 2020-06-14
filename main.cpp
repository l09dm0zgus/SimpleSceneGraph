#include <iostream>
#include <map>
using namespace std;
/**
 * @brief The GameObject class Abstract Class.
 */
class GameObject
{
public:
    virtual void setPosition(float x,float y) = 0;
    virtual float getX() = 0;
    virtual float getY() = 0;
    virtual void addChildren(GameObject *child,string name) = 0;
    virtual GameObject *getChild(string name)=0;
protected:
    map<string,GameObject*> childrens;
    map<string,GameObject*>::iterator it;
};
/**
 * @brief The Object class Child class of GameObject;
 */
class Object:public GameObject
{
public:
    void setPosition(float x, float y) override
    {
        this->x = this->x + x;
        this->y = this->y + y;
        for(it = childrens.begin();it!=childrens.end();it++)
        {
            it->second->setPosition(x,y);
        }
    }
    float getX() override
    {
        return  x;
    }
    float getY() override
    {
        return  y;
    }
    void addChildren(GameObject *child,string name) override
    {
        child->setPosition(x,y);
        childrens[name] = child;
    }
    GameObject *getChild(string name) override
    {
        return childrens[name];
    }

private:
    float x=0,y=0;

};

int main()
{
    Object scene,player,gun;
    GameObject *test;
    //add childs
    scene.addChildren(&player,"player");
    player.addChildren(&gun,"gun");
    //get position
    scene.setPosition(6,5);
    test = player.getChild("gun");
    cout<<"X: "<<test->getX()<<"Y:"<<test->getY()<<endl;
    player.setPosition(3,1);
    test = player.getChild("gun");
    cout<<"X: "<<test->getX()<<"Y:"<<test->getY()<<endl;
    gun.setPosition(2,2);
    test = player.getChild("gun");
    cout<<"X: "<<test->getX()<<"Y:"<<test->getY()<<endl;
    return 0;
}
