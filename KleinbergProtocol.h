#include <iostream>
#include <vector>

#include "Node.h"

class KleinbergProtocol {
public:
    int rows;
    int cols;
    std::vector<std::vector<Node*>> grid;

    KleinbergProtocol(int rows, int cols) : rows(rows), cols(cols) {
        // inicializa a grade com nós
        grid.resize(rows, std::vector<Node*>(cols, nullptr));
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                grid[r][c] = new Node(r * cols + c);
            }
        }

        //configura as conexões toroidais
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                grid[r][c]->north = grid[(r - 1 + rows) % rows][c];
                grid[r][c]->south = grid[(r + 1) % rows][c];
                grid[r][c]->east = grid[r][(c + 1) % cols];
                grid[r][c]->west = grid[r][(c - 1 + cols) % cols];
            }
        }
    }
    //Destrutor da classe Torus2D
    ~KleinbergProtocol(){
         //configura as conexões toroidais
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                delete grid[r][c];
                
            }
        }
    }

    void drawGrid(){
         //configura as conexões toroidais
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                std::cout << grid[r][c]->id << " ";
            }
        std::cout << std::endl;
        }
    }
    // lista de vizinhos diretors usando Kleinberg
    void drawNeighbour(int rows, int cols){
        KleinbergProtocol kleinberg(rows, cols);
        
        std::cout << "North ID: " << kleinberg.grid[0][0]->north->id << std::endl;
        std::cout << "South ID: " << kleinberg.grid[0][0]->south->id << std::endl;
        std::cout << "East ID: " << kleinberg.grid[0][0]->east->id << std::endl;
        std::cout << "West ID: " << kleinberg.grid[0][0]->west->id << std::endl;
    }
};