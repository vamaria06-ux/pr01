#include <iostream>

int ** convert( const int * t, size_t n, const size_t * lns, size_t rows){
  int ** result = new int*[rows]
  const int* current =t;

  for ( size_t i=0; i < rows; ++i)
  {
    size_t len = lns[i];
    result[i]= new int[len];

    for( size_t j=0; j<len; ++j)
    {
      result[i][j]= *current;
      current++;
    }
  }
  return result;
}

void destroy(int ** mtx, size_t created )
{
  for(size_t i=0; i< created;i++)
  {
    delete[] mtx[i];
  }
  delete[] mtx; 
}
int ** creat(size_t rows, size_t cols){
  int **  mtx=new int * [rows];
  size_t created=0;
  try
  {
    for(; created<rows;++created)
    {
      mtx[created]=new int[cols];
      
    }
  }
  catch(const std::bad_alloc & e)
  {
    destroy(mtx, created);
    throw; 
  }
  return mtx;
}

int ** construct(int ** mtx, int init , size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      mtx[i][j] = init;
    }
  }
  return mtx;
}
void input( int ** mtx, size_t rows, size_t cols)
{
  for (size_t i=0; i < rows;i++)
  {
    for(size_t j=0; j < cols, j++)
   {
      std::cin>>mtx[i][j];
   }
  }
}

void output( int ** mtx, size_t rows, size_t cols)
{
  for (size_t i=0; i < rows; ++i)
  {
    //std::cout<<mtx[i][0];
    for(size_t j=0; j < cols, ++j)
   {
      std::cout<<'' <<mtx[i][j];
   }
    std::cout << '\n';
  }
}

int main(){
  size_t r=0,c=0;
  std::cin>> r >> c;
  if (!std::cin)
  {
    std::cerr<<"Error\n";
    return 2;
  }
  int ** matrix = nullptr;
  try
  {
    matrix=creat(r,c);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what()<<'\n';
    return 1;
  }
  std::cout<<"created\n";
  construct(matrix,2,r,c);
  //std::cout<<matrix[0][0]<<"\n";
  input(matrix,r,c);
  if(!std::cin)
  {
    destroy(matrix,r);
    std::cerr<<"Input error\n";
    return 1;
  }
  output(matrix,r,c);
  destroy(matrix,r);
}
