#include "TotalControl.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>


// Constructor for the entire class
dictatorship::dictatorship(std::string cityFname, std::string connectFname, std::string civilFname)
{
    citizen * temp = new citizen("", "", "");
    nullNode = temp;
    nullNode->red = false;

    std::fstream infile;
    std::string cityName,line,city1,city2,name,hair,eyes;
    int population;

    // Reads the cities available
    infile.open(cityFname);
    while (getline(infile,cityName))
    {
        population = 0;

        addVertex(cityName,population);
    }
    infile.close();

    // Reads the connections from city to city, and populations
    infile.open(connectFname);
    while (getline(infile,line))
    {
        std::stringstream linestream(line);
        getline(linestream,city1,',');
        getline(linestream,city2,',');

        addEdge(city1,city2);
    }
    infile.close();

    // Reads civilians and places them in the proper city
    infile.open(civilFname);
    getline(infile,line);
    while (getline(infile,line))
    {
        std::stringstream linestream(line);
        getline(linestream,cityName,',');
        getline(linestream,name,',');
        getline(linestream,hair,',');
        getline(linestream,eyes);

        bool found = selectCity(cityName);
        if (found)
            addCitizen(name,hair,eyes);
    }
    infile.close();

    currentCity = 0;
}

/*****************************************************************/

dictatorship::~dictatorship()
{
    for (int i = 0; i < vertices.size(); i++)
    {
        currentCity = i;
        if (vertices[i].population != 0)
        {
        citizen * temp = vertices[currentCity].rootCitizen;
        vertices[currentCity].rootCitizen = nullNode;
        recursiveDelete(temp);
        }
    }
    delete nullNode;
}

/*****************************************************************/

// recursive delete
void dictatorship::recursiveDelete(citizen * node)
{
    if (node->left != nullNode)
        recursiveDelete(node->left);
    if (node->right != nullNode)
        recursiveDelete(node->right);

    std::cout << "Nuclear fallout has killed: " << node->name << " from " << vertices[currentCity].name << std::endl;
    delete node;
}

/*****************************************************************/

void dictatorship::addVertex(std::string n, int pop){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            std::cout<<vertices[i].name<<" found."<<std::endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        v.population = pop;
        v.rootCitizen = nullNode;
        vertices.push_back(v);

    }
}

/*****************************************************************/

void dictatorship::addEdge(std::string v1, std::string v2)
{
    for(int i = 0; i < vertices.size(); i++)
        {
        if(vertices[i].name == v1)
        {
            for(int j = 0; j < vertices.size(); j++)
            {
                if(vertices[j].name == v2 && i != j)
                {
                    adjVertex av;
                    av.v = &vertices[j];
                    vertices[i].adj.push_back(av);
                }
            }
        }
    }
}

/*****************************************************************/

void dictatorship::addCitizen(std::string citizName, std::string hairColor, std::string eyeColor)
{
    citizen * temp = vertices[currentCity].rootCitizen;
    citizen * parent = nullNode;

    citizen * addme = new citizen(citizName,hairColor,eyeColor);
    addme->left = nullNode;
    addme->right = nullNode;

    vertices[currentCity].population++;

    while(temp != nullNode)
    {
        parent = temp;
        if (addme->name < temp->name)
            temp = temp->left;
        else
            temp = temp->right;
    }
    addme->parent = parent;
    if (parent == nullNode)
    {
        vertices[currentCity].rootCitizen = addme;
    }
    else if(addme->name < parent->name)
    {
        parent->left = addme;
    }
    else
    {
        parent->right = addme;
    }
    addBalance(addme);
}

/*****************************************************************/

void dictatorship::addBalance(citizen * node)
{
    while (node != vertices[currentCity].rootCitizen && node->parent->red)
    {
       if (node->parent == node->parent->parent->left)
        {
            citizen * uncle = node->parent->parent->right;
            if (uncle->red)
            {
                RBCase1(node, uncle);
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->right)
                {
                    node = node->parent;
                    leftRotate(node);
                }
                RBCase3Left(node);
            }
        }
        else
        {
            citizen * uncle = node->parent->parent->left;
            if (uncle->red)
            {
                RBCase1(node, uncle);
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->left)
                {
                    node = node->parent;
                    rightRotate(node);
                }
                RBCase3Right(node);
            }
        }
    }
    vertices[currentCity].rootCitizen->red = false;
}


/*****************************************************************************************/

void dictatorship::RBCase1(citizen * node, citizen * uncle)
{
    node->parent->red = false;
    uncle->red = false;
    node->parent->parent->red = true;
}

/*****************************************************************************************/

void dictatorship::RBCase3Left(citizen * node)
{
    node->parent->red = false;
    node->parent->parent->red = true;
    rightRotate(node->parent->parent);
}

/*****************************************************************************************/

void dictatorship::RBCase3Right(citizen * node)
{
    node->parent->red = false;
    node->parent->parent->red = true;
    leftRotate(node->parent->parent);
}

/*****************************************************************************************/

void dictatorship::leftRotate(citizen * node1)
{
    citizen * node2 = node1->right;
    node1->right = node2->left;
    if (node2->left != nullNode)
        node2->left->parent = node1;
    node2->parent = node1->parent;
    if (node1->parent == nullNode)
        vertices[currentCity].rootCitizen = node2;
    else if (node1 == node1->parent->left)
        node1->parent->left = node2;
    else
        node1->parent->right = node2;
    node2->left = node1;
    node1->parent = node2;
}

/*****************************************************************************************/

void dictatorship::rightRotate(citizen * node1)
{
    citizen * node2 = node1->left;
    node1->left = node2->right;
    if (node2->right != nullNode)
        node2->right->parent = node1;
    node2->parent = node1->parent;
    if (node1->parent == nullNode)
        vertices[currentCity].rootCitizen = node2;
    else if (node1 == node1->parent->left)
        node1->parent->left = node2;
    else
        node1->parent->right = node2;
    node2->right = node1;
    node1->parent = node2;
}

/*****************************************************************************************/

void dictatorship::printCurrentCity()
{
    std::cout << "======Current City======" << std::endl;
    std::cout << vertices[currentCity].name << " | Population: " << vertices[currentCity].population << std::endl;
    std::cout << "======Adjacent Cities======" << std::endl;
    for (int i = 0; i < vertices[currentCity].adj.size(); i++)
        std::cout << vertices[currentCity].adj[i].v->name << " | Population: " << vertices[currentCity].adj[i].v->population << std::endl;
}

/*****************************************************************************************/

void dictatorship::listCities()
{
    std::cout << "======All Cities======" << std::endl;
    for (int i = 0; i < vertices.size(); i++)
    {
        std::cout << vertices[i].name << " | Population: " << vertices[i].population << std::endl;
    }
}

/*****************************************************************************************/

void dictatorship::listCitizens()
{
    recursiveList(vertices[currentCity].rootCitizen);
}

/*****************************************************************************************/

void dictatorship::recursiveList(citizen * node)
{
    if (node->left != nullNode)
        recursiveList(node->left);
    std::cout << "Citizen: " << node->name << " | Hair: " << node->hair << " | Eyes: " << node->eyes << std::endl;
    if (node->right != nullNode)
        recursiveList(node->right);
}

/*****************************************************************************************/

bool dictatorship::selectCity(std::string cityName)
{
    bool found = false;
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i].name == cityName)
        {
            currentCity = i;
            found = true;
        }
    }
    if (!found)
        std::cout << cityName << " was not found." << std::endl;
    return found;
}

/*****************************************************************************************/

void dictatorship::executeCitizen(std::string citizName)
{
    citizen * node = findCitizen(citizName, vertices[currentCity].rootCitizen);
    citizen * minNode = nullNode;
    citizen * x = nullNode;
    if (node == nullNode)
        std::cout << "Citizen not found." << std::endl;
    else
    {
        vertices[currentCity].population--;
        if (node != vertices[currentCity].rootCitizen)
        {
            if (node->left == nullNode && node->right == nullNode) //no children
            {
                if (node->parent->name > node->name)
                {
                    node->parent->left = nullNode;
                    x = node->parent->left;
                }
                else
                {
                    node->parent->right = nullNode;
                    x = node->parent->right;
                }
            }
            else if (node->left != nullNode && node->right != nullNode) //two children
            {
                minNode = treeMinimum(node->right);
                if (minNode == node->right)
                {
                    if (node->parent->name > node->name)
                        node->parent->left = minNode;
                    else
                        node->parent->right = minNode;
                    minNode->parent = node->parent;
                    minNode->left = node->left;
                    node->left->parent = minNode;
                }
                else
                {
                    minNode->parent->left = minNode->right;
                    minNode->right->parent = minNode->parent;
                    minNode->parent = node->parent;
                    if (node->parent->name > node->name)
                        node->parent->left = minNode;
                    else
                        node->parent->right = minNode;
                    minNode->left = node->left;
                    minNode->right = node->right;
                    node->right->parent = minNode;
                    node->left->parent = minNode;
                }
                x = minNode;
            }
            else // one child
            {
                if (node->left != nullNode)
                {
                    x = node->left;
                    node->parent->left = x;
                }
                else
                {
                    x = node->right;
                    node->parent->right = x;
                }
                x->parent = node->parent;
            }
        }
        else if (node != nullNode)
        {
            if (node->left == nullNode && node->right == nullNode) //no children
                vertices[currentCity].rootCitizen = nullNode;
            else if (node->left != nullNode && node->right != nullNode) //two children
            {
                minNode = treeMinimum(node->right);
                if (minNode == node->right)
                {
                    vertices[currentCity].rootCitizen = minNode;
                    minNode->parent = nullNode;
                    minNode->left = node->left;
                    minNode->left->parent = minNode;
                }
                else
                {
                    vertices[currentCity].rootCitizen = minNode;
                    minNode->parent->left = minNode->right;
                    minNode->right->parent = minNode->parent;
                    minNode->parent = nullNode;
                    minNode->left = node->left;
                    minNode->right = node->right;
                    node->right->parent = minNode;
                    node->left->parent = minNode;
                }
                x = minNode;
            }
            else //one child
            {
                if (node->left != nullNode)
                    x = node->left;
                else
                    x = node->right;
                vertices[currentCity].rootCitizen = x;
                x->parent = nullNode;
            }
        }
        if (!node->red)
        {
            x->parent = node->parent;
            deleteBalance(x);
        }
        std::cout << "Executed: " << node->name << " | Hair: " << node->hair << " | Eyes: " << node->eyes << std::endl;
        delete node;
    }
}

/*****************************************************************************************/

// find minimum value on branch in tree
citizen * dictatorship::treeMinimum(citizen * node)
{
    while (node->left != nullNode)
        node = node->left;
    return node;
}

/*****************************************************************************************/

void dictatorship::deleteBalance(citizen * node)
{
    while (node != vertices[currentCity].rootCitizen && !node->red)
    {
        if (node == node->parent->left) // left child
        {
            citizen * s = node->parent->right;
            if (s->red)
            {
                s->red = false;
                node->parent->red = true;
                leftRotate(node->parent);
                s = node->parent->right;
            }
            if (!s->left->red && !s->right->red)
            {
                s->red = true;
                node = node->parent;
            }
            else if (s->left->red && !s->right->red)
            {
                s->left->red = false;
                s->red = true;
                rightRotate(s);
                s = node->parent->right;
            }
            else
            {
                s->red = node->parent->red;
                node->parent->red = false;
                s->right->red = false;
                leftRotate(node->parent);
                node = vertices[currentCity].rootCitizen;
            }
        }
        else // right child
        {
            citizen * s = node->parent->left;
            if (s->red)
            {
                s->red = false;
                node->parent->red = true;
                rightRotate(node->parent);
                s = node->parent->left;
            }
            if (!s->right->red && !s->left->red)
            {
                s->red = true;
                node = node->parent;
            }
            else if (s->right->red && !s->left->red)
            {
                s->right->red = false;
                s->red = true;
                leftRotate(s);
                s = node->parent->left;
            }
            else
            {
                s->red = node->parent->red;
                node->parent->red = false;
                s->left->red = false;
                rightRotate(node->parent);
                node = vertices[currentCity].rootCitizen;
            }
        }
    }
}

/*****************************************************************************************/

// finds a citizen
citizen* dictatorship::findCitizen(std::string citizName, citizen*node)
{
    if (node != nullNode)
    {
        if (node->name == citizName)
            return node;
        else if (node->name > citizName)
            return findCitizen(citizName, node->left);
        else
            return findCitizen(citizName, node->right);
    }
    else
        return nullNode;
}

/*****************************************************************************************/

void dictatorship::glassCity(std::string cityName)
{
    bool found = selectCity(cityName);
    if (found)
    {
        std::cout << "You fire a nuclear missile at " << vertices[currentCity].name << std::endl;
        recursiveDelete(vertices[currentCity].rootCitizen);
        vertices[currentCity].population = 0;
    }
}

/*****************************************************************************************/

void dictatorship::moveCitizen(std::string citizName, std::string cityName)
{
    citizen* moveme = findCitizen(citizName,vertices[currentCity].rootCitizen);
    if (moveme == nullNode)
    {
        std::cout << citizName << " not found." << std::endl;
    }
    else
    {
        std::string hair = moveme->hair;
        std::string eyes = moveme->eyes;
        executeCitizen(citizName);
        selectCity(cityName);
        addCitizen(citizName,hair,eyes);
    }
}

/*****************************************************************************************/

void dictatorship::relocatePopulace(std::string emptyCity, std::string relocateCity)
{
    bool found = selectCity(emptyCity);
    if (found)
    {
        while (vertices[currentCity].population != 0)
        {
            recursiveMove(vertices[currentCity].rootCitizen, emptyCity, relocateCity);
            found = selectCity(emptyCity);
        }
    }
}

/*****************************************************************************************/

void dictatorship::recursiveMove(citizen * node, std::string emptyCity, std::string relocateCity)
{
    bool found = selectCity(emptyCity);
    if (found)
        moveCitizen(node->name, relocateCity);

    if (node->left != nullNode)
        recursiveMove(node->left, emptyCity, relocateCity);
    if (node->right != nullNode)
        recursiveMove(node->right, emptyCity, relocateCity);
}

/*****************************************************************************************/

/* Could not get eugenics function working without crazy segfaults
void dictatorship::eugenics(std::string hairColor, std::string eyeColor)
{
    std::cout << "Your roaming death squads are given the order, and they return with a list." << std::endl;
    std::cout << "The list reads:" << std::endl;
    for (int i=0; i < vertices.size(); i++)
    {
        bool found = selectCity(vertices[i].name);
        std::cout << "~~~~~" << vertices[i].name << "~~~~~" << std::endl;
        if (vertices[currentCity].population != 0)
            recursiveEugenics(vertices[i].rootCitizen, hairColor, eyeColor);
        else
            std::cout << "Empty" << std::endl;
    }
}


void dictatorship::recursiveEugenics(citizen * node, std::string hairColor, std::string eyeColor)
{
    if (node->left != nullNode)
        recursiveEugenics(node->left, hairColor, eyeColor);
    if (node->right != nullNode)
        recursiveEugenics(node->right, hairColor, eyeColor);

    if ((hairColor == "any" || hairColor != node->hair) && (eyeColor == "any" || eyeColor != node->eyes))
    {
        std::cout << node->name << " " << vertices[currentCity].name << std::endl;
        executeCitizen(node->name);
    }
}
*/
