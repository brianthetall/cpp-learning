#include <iostream>
#include <python3.7m/Python.h>


int main(int argc, char **argv){

  Py_Initialize(); /* init python */

  PyRun_SimpleString("print('Hello embedded world!')");

  /* use C extension module above */
  PyRun_SimpleString(
		     "for i in range(4):\n"
		     "\tprint(i),\n"
		     "\tprint('Hello, sexy')\n\n"
		     );
  PyRun_SimpleString("print('Bye embedded world!')");

  return 0;
}
