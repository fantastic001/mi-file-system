/*
    Marina Ivanovic
    Project in Petnica Science Center
*/

#ifndef __COMMANDS
#define __COMMANDS

#include <stdio.h>
#include <cstdlib>
#include <map>
#include <string>
#include <string.h>

#include "../include/node.h"
#include "../include/memory.h"

/*
    This class defines methods for every command in mi-file-system.
*/

class commands
{
    private:
        std::map<std::string, int> mm; // codes of commands

    public:
        void _list_directory(node* curr);
        node* _change_directory(node* curr, char* name);
        void _make_directory(memory* part, node* curr, char* name);
        void _make_file(memory* part, node* curr, char* name);
        void _delete(memory* part, node* curr);

        void map_commands();
        void read_commands(memory* part, node* curr);
};

#endif
