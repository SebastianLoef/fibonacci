#define PY_SSIZE_T_CLEAN
#include <Python.h>

int fib_internal(int n)
{
    int a = 0, b = 1, c = 0;
    for (int i = 0; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
static PyObject *my_c_module_fib(PyObject *self, PyObject *args)
{
    unsigned n;
    if (!PyArg_ParseTuple(args, "i", &n))
        return NULL;

    PyObject *out;
    out = PyLong_FromLong(fib_internal(n));
    return out;
}

static PyMethodDef my_c_module_methods[] = {
    {"fib", my_c_module_fib, METH_VARARGS, "Returns a list with the first n Fibonacci numbers."},
    {NULL, NULL, 0, NULL} /* Sentinel */
};

static struct PyModuleDef my_c_module = {
    PyModuleDef_HEAD_INIT,
    "my_c_module",                 /* name of module */
    "My first Python module in C", /* module documentation, may be NULL */
    -1,                            /* size of per-interpreter state of the module,
                                      or -1 if the module keeps state in global variables. */
    my_c_module_methods};

PyMODINIT_FUNC PyInit_my_c_module(void)
{
    return PyModule_Create(&my_c_module);
}