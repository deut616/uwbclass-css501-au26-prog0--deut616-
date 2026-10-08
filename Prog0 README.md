# Housing Selection Points Calculator

A command-line C++ program that asks a few questions and calculates a student's housing selection points.

## Build and run

Requires a C++ compiler such as g++ (C++11 or later).

```
g++ -o housing housing.cpp
./housing
```

On Windows, run `housing.exe` instead of `./housing`.

## How points are calculated

| Question | Points |
|---|---|
| Class year | Freshman +10, Sophomore +7, Junior +4, Senior +2 |
| Age | max(0, (age - 18) / 2), using integer division |
| Full-time off-campus program | Yes +1, No +0 |
| Graduating this year (seniors only) | Yes +3, No +0 |
| Academic probation | -1 |
| Academic suspension | -2 |
| Disciplinary probation | -3 |

## Example

```
What is your class year?
1. Freshman
2. Sophomore
3. Junior
4. Senior
Enter your choice (1-4): 2
Added 7 points
...
You have 9 housing points.
```

## Notes and limitations

- Menu questions reject out-of-range and non-numeric input and ask again.
- The age question does not validate input, so entering a non-number will break it.
## Design decisions

`getChoice` is a helper function that prints a question and its options, then keeps asking until the user enters a valid number. I used it instead of repeating the same input loop for each question, which keeps `main()` easier to read and means the validation only has to be written and fixed in one place.