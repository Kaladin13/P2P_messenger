#include "main.hpp"
#include <Python.h>

std::string greet() {
    return "Boost, Python";
}

BOOST_PYTHON_MODULE(main) {
    boost::python::def("greet", &greet);
}