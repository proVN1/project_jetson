#include <Python.h>
#include <unistd.h>

int main() {
    //initialize python inter preter
    Py_Initialize();

    // Import module Python including API
    PyObject* module = PyImport_ImportModule("GPIO");

    // Checking the connecting module Python
    if (module != NULL) {
        
        // Get the SetUp function from module Python
        PyObject* setupFunc = PyObject_GetAttrString(module, "GPIO_SetUp");
        
        // Check the setupFunc creating or not
        if (!setupFunc) {
            PyErr_SetString(PyExc_AttributeError, "GPIO_SetUp function not found");
            return NULL;  
        }
        if (setupFunc && PyCallable_Check(setupFunc)) {
            //creating a tupe includes the argument
            PyObject* args1 = PyTuple_New(1); 
            PyTuple_SetItem(args1, 0, PyUnicode_FromString("BOARD")); // set BOARD or BCM

            //calling the func and check the result
            PyObject* result1 = PyObject_CallObject(setupFunc, args1);
            Py_DECREF(args1);    //decrement reference count
            if (result1 != NULL) {
                Py_DECREF(result1);
            } else {
                PyErr_Print();
            }
            Py_DECREF(setupFunc);
        }

        // Calling SetModePin function
        PyObject* setmodeFunc = PyObject_GetAttrString(module, "GPIO_SetModePin");
        if (!setmodeFunc) {
            PyErr_SetString(PyExc_AttributeError, "GPIO_SetModePin function not found");
            return NULL;
        }
        if (setmodeFunc && PyCallable_Check(setmodeFunc)) {
            PyObject* args2 =PyTuple_New(2); 
            //set the pin 12 output 
            PyTuple_SetItem(args2, 0, PyLong_FromLong(12));
            PyTuple_SetItem(args2, 1, PyUnicode_FromString("OUPUT")); 
            PyObject* result2 = PyObject_CallObject(setmodeFunc, args2);
            Py_DECREF(args2);
            if (result != NULL) {
                Py_DECREF(result2);
            } else {
                PyErr_Print();
            }
            Py_DECREF(setmodeFunc);
        }

        // Calling Output function
        PyObject* outputFunc = PyObject_GetAttrString(module, "GPIO_Output");
        if (!outputFunc) {
            PyErr_SetString(PyExc_AttributeError, "GPIO_Output function not found");
            return NULL;
        }
        if (outputFunc && PyCallable_Check(outputFunc)) {
            PyObject* args3 =PyTuple_New(2); 
            //set the pin 12 output 
            PyTuple_SetItem(args3, 0, PyLong_FromLong(12));
            PyTuple_SetItem(args3, 1, PyUnicode_FromString("HIGH")); 
            PyObject* result = PyObject_CallObject(outputFunc, args2);
            usleep(1000000); //delay 1s
            PyTuple_SetItem(args3, 1, PyUnicode_FromString("LOW")); 
            result = PyObject_CallObject(outputFunc, args3);
            Py_DECREF(args3);
            if (result != NULL) {
                Py_DECREF(result);
            } else {
                PyErr_Print();
            }
            Py_DECREF(setmodeFunc);
            }
        }
        // Giải phóng module
        Py_DECREF(module);
    } else {
        PyErr_Print();
    }

    // Kết thúc trình thông dịch Python
    Py_Finalize();

    return 0;
}