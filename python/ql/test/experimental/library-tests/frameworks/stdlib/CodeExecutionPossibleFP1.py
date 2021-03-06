# without this, `eval("print(42)")` becomes invalid syntax in Python 2, since print is a
# statement
from __future__ import print_function


def eval(*args, **kwargs):
    raise Exception("no eval")


# This function call might be marked as a code execution, but it actually isn't.
eval("print(42)")  # $f+:getCode="print(42)"
