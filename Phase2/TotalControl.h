#include <iostream>
#include <vector>
#include <string>

struct citizen
{
    citizen * parent;
    citizen * right;
    citizen * left;
    std::string name;
    std::string hair;
    std::string eyes;
    bool red;

    citizen(std::string addName, std::string addHair, std::string addEyes)
    {
        name = addName;
        hair = addHair;
        eyes = addEyes;

        parent = nullptr;
        right = nullptr;
        left = nullptr;
        red = true;
    }
};

struct vertex;

struct adjVertex
{
    vertex *v;
};

struct vertex
{
    std::string name;
    std::vector<adjVertex> adj; // could result in errors? used to be vector<adjVertex<T> >
    citizen * rootCitizen;
    int population;
};

class dictatorship
{
public:
    dictatorship(std::string cityFname, std::string connectFname, std::string civilFname);
    ~dictatorship();
    void listCitizens();
    void listCities();
    bool selectCity(std::string cityName);
    void executeCitizen(std::string citizName);
    void addCitizen(std::string citizName, std::string hairColor, std::string eyeColor);
    void glassCity(std::string cityName);
    void eugenics(std::string hairColor, std::string eyeColor);
    void moveCitizen(std::string citizName, std::string cityName);
    void relocatePopulace(std::string emptyCity, std::string relocateCity);
    void printCurrentCity();
private:
    std::vector<vertex> vertices;
    citizen *nullNode;
    int currentCity;
    void addEdge(std::string v1, std::string v2);
    void addVertex(std::string name, int population);
    void addBalance(citizen * node);
    void RBCase1(citizen * node, citizen * uncle);
    void RBCase3Left(citizen * node);
    void RBCase3Right(citizen * node);
    void leftRotate(citizen * node);
    void rightRotate(citizen * node);
    void deleteBalance(citizen * node);
    citizen * findCitizen(std::string name, citizen *node);
    citizen * treeMinimum(citizen* node);
    void recursiveList(citizen * node);
    void recursiveDelete(citizen * node);
    void recursiveMove(citizen * node, std::string emptyCity, std::string relocateCity);
    void recursiveEugenics(citizen * node, std::string hairColor, std::string eyeColor);
};
