#include "../include/main.hpp"

std::string greet() {
    return "Boost, Python";
}

BOOST_PYTHON_MODULE(ndt) {
    boost::python::def("start", &greet);
}


