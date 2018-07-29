# Search Maximum

## Search Maximum Algorithm
```py3
# py3
def maximum(x):
    """
    x: a list of numbers
    """
    max = x[0]
    for i in range(1, len(x)):
        if x[i] > max:
            max = x[i]
    return max
```


