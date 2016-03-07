#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
//#include "parser.h"

int main() {

  screen s;

  color c;
  c.red = 33;
  c.green = 99;
  c.blue = 0;
  clear_screen(s);

  struct matrix *edges;
  struct matrix *transform;

  edges = new_matrix(4, 1);
  
  add_edge(edges, 30, 35, 0, 35, 40, 0);
  add_edge(edges, 40, 45, 0, 45, 50, 0);
  add_edge(edges, 50, 55, 0, 55, 66, 0);
  add_edge(edges, 39, 30, 0, 3, 300, 0);
  int x;
  for (x = 0; x <50; x++) {
    add_edge(edges, x*x*x%600, x*6, 0, 60, x*3, 0);
  }
  scalar_mult(1.1, edges);


  draw_lines(edges,s,c);
  
  int i;
  for(i=0; i<50; i++){
    scalar_mult(.5, edges);
    draw_lines(edges,s,c);
  }

  display(s);
  save_extension(s, "matrix.png");

  
  free_matrix( transform );
  free_matrix( edges );

}  
