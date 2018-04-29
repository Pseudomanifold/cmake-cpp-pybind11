#include <pybind11/pybind11.h>

#include <string>

class Example
{
public:
  Example( double a )
    : _a( a)
  {
  }

  Example& operator+=( const Example& other )
  {
    _a += other._a;
    return *this;
  }

private:
  double _a;
};

PYBIND11_MODULE(example, m)
{
  m.doc() = "Python bindings for an example library";

  namespace py = pybind11;

  py::class_<Example>(m, "Example")
    .def( "__init__",
      [] ( Example& instance, double a )
      {
        new (&instance) Example( a );
      }
    )
    .def( "__iadd__", &Example::operator+= );
}
