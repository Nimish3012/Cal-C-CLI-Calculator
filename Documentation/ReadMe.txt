 **Workflow Summary:**
   - User inputs a mathematical expression.
   - The expression is processed to remove spaces.
   - The code checks for the presence of operators.
   - If operators are found, it performs calculations following DMAS order.
   - The result is displayed, and the user is prompted to continue or exit.
   - The loop continues until the user chooses to exit.


The flow of the program from input to output can be outlined as follows:

1. **Initialization:**
   - Global variables (`Exp`, `result`, `length1`, `length2`) are declared.
   - User-defined functions (`input`, `HasOP`, `isDecimal`, `update`, `performOP`, `evaluation`) are declared.

2. **Main Function (`main`):**
   - Welcomes the user and explains the calculator's functionality.
   - Enters a do-while loop to allow multiple calculations.
   - Within the loop:
     - Calls `input` function to get a mathematical expression from the user.
     - Checks if the expression contains any basic arithmetic operators using `HasOP`.
     - If operators are present, calls the `evaluation` function to perform calculations.
     - Outputs the final result or an error message for invalid syntax.
     - Asks the user if they want to continue (`Y` or `N`).
   - Exits the loop if the user chooses not to continue.
   - Displays a closing message.

3. **Input Function (`input`):**
   - Prompts the user to enter a mathematical expression.
   - Reads the input as a string.
   - Removes spaces from the input string.
   - Returns the processed expression.

4. **Operator Checking Function (`HasOP`):**
   - Checks if the expression contains any of the basic arithmetic operators (`/`, `*`, `+`, `-`).
   - Returns `true` if an operator is found, otherwise `false`.

5. **Decimal Checking Function (`isDecimal`):**
   - Checks if a character is a digit or a decimal point.
   - Returns `true` if the character is a digit or a decimal point, otherwise `false`.

6. **Update Function (`update`):**
   - Replaces a substring in the expression with a new result.
   - Takes the starting index, length, and the new result as parameters.
   - Updates the global `Exp` variable.

7. **Perform Operation Function (`performOP`):**
   - Performs a specified arithmetic operation on the expression.
   - Identifies the operands, calculates the result, and updates the expression using the `update` function.

8. **Evaluation Function (`evaluation`):**
   - Calls `performOP` for each arithmetic operation (`/`, `*`, `+`, `-`) in the order of DMAS (Division, Multiplication, Addition, Subtraction).
   - Evaluates the expression by iteratively performing operations until no more operators are found.

 **Workflow Summary:**
   - User inputs a mathematical expression.
   - The expression is processed to remove spaces.
   - The code checks for the presence of operators.
   - If operators are found, it performs calculations following DMAS order.
   - The result is displayed, and the user is prompted to continue or exit.
   - The loop continues until the user chooses to exit.
