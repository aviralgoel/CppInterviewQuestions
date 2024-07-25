///////////////////////////////////////////////////////////////////////////
// PACKING AND PADDING IN C++
// 
// Padding is the process of adding extra bytes to the structure to make it aligned.


// padding - adding extra bytes to the structure
// packing - removing extra bytes from the structure

struct Base
{
	char a;
	char b;
	int i;
	char c;
};
// size of the structure is 12 bytes
// [a][b][padding][padding][i][i][i][i][c][padding][padding][padding]
// To align the entire structure to the largest alignment requirement (4 bytes in this case), 
// 3 bytes of padding are added at the end.
struct Base1
{
	char a;
	char b;
	char c;
	int i;
};

// size of the structure is 7 bytes
// [a][b][c][padding][i][i][i][i]
// 1 bytte data type, goes to multiple of 1 location
// 2 bytte data type, goes to multiple of 2 location
// 4 bytte data type, goes to multiple of 4 location
// 8 bytte data type, goes to multiple of 8 location
// we can use '#pragma pack(1)' to disable padding
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// WHAT IS COMPILER, LINKER, LOADER ?
// 
// Compiler - converts high level language to machine code
// Linker - links the object files to create an executable file
// Loader - loads the executable file into memory

// Source Code - written in high level language
// Preprocessing stage - removes comments, expands macros, includes header files
// Compilation stage - converts source code to assembly code
// Assembly stage - converts assembly code to object code
// Linking stage - links object files to create an executable file, static libraries are linked at this stage
// Loader stage - loads the executable file into memory, dynamic libraries are linked at this stage
// Execution stage - executes the program
// Source Code -> Preprocessing stage (.i files) -> Compilation stage (.s files) -> Assembly stage (.o files) -> 
// Linking stage (.exe files) -> Loader stage -> Execution stage
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// HOW DELETE KNOWS HOW MUCH MEMORY TO DEALLOCATE ?
//
// Over allocation -> allocate required memory + some extra memory (that stores the size of the memory allocated)
// Base *bp = new Base[n];
// char* tmp = (char*) operator new[] (sizeof(Base) * n + sizeof(int));
// Base* p = (Base*) (tmp + sizeof(int));
// *(int*) tmp = n;
// for(int i = 0; i < n; i++)
// {
//     new (p+i) Base(); // placement new
// }
// delete[] bp;

// Assosicative allocation -> store the p* to the memory allocated and size of the memory allocated in a data structure
// Base *bp = new Base[n];
// assosicative data structure -> {bp, size}
// delete[] bp;
// size_t size = assosicative[bp];
// while(size--!=0)
// {
//     (bp+i)->~Base();
// }
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// DIFFERENCE BETWEEN POINTER AND REFERENCE
// 
// 1. Pointer can be NULL, reference can't be NULL
// 2. memory address is not given to reference, memory address is given to pointer
// 3. there is always a table for variable name -> memory address (symbol table)
// | variable name | memory address |
// | a             | 1000           |
// | referenceOfA  | 1000           |
// 4. reference is an alias to the variable, pointer is a variable that stores the memory address of another variable
// 5. reference can't be re-assigned, pointer can be re-assigned
// 6. you can't have an array of references, you can have an array of pointers
// 7. you can't do pointer arithmetic on references, you can do pointer arithmetic on pointers
// 8. you can't have a reference to a reference, you can have a pointer to a pointer
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////



