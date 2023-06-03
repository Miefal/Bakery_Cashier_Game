# Bakery_Cashier_Game
"Bakery Cashier Game" is a fun and interactive program that simulates the role of a cashier at a bakery. Players can test their skills by giving the correct change to customers who purchase a variety of bakery items. The game offers a randomized selection of items and random payment amounts.
## Bakery Cashier Game

This is a simple cashier game where you play the role of a cashier at a bakery. Your goal is to give the correct change to customers who purchase bakery items. The game is written in C++ and can be run on a C++ compiler.

### How to Play

1. The program will display a welcome message.

2. For each customer, a random number of items (between 1 and 3) will be selected from a predefined list of bakery items. The types of items include Baguette, Croissant, Sourdough, Multigrain, Traditional, Muffin, Cake Slice, Cappuccino, Latte, Whole Wheat, Rye, and more.

3. The program will display the selected items and their prices in euros.

4. A total price will be calculated based on the selected items.

5. The program will randomly generate the amount paid by the customer. In some cases, the customer may give the exact total price, while in other cases, a random amount between the total price and 50 euros will be generated.

6. The program will display the total price and the amount paid.

7. You need to calculate and enter the correct change in euros and cents. The program will compare your input with the calculated change.

8. If you enter the correct change, the program will display a congratulatory message and the amount of change to be given to the customer. If your input is incorrect, the program will display the correct change.

9. The program will display the items purchased by the customer.

10. You can choose to serve another customer or exit the game.

### How to Run

To run the game, follow these steps:

1. Compile the program using a C++ compiler. For example, you can use the following command:

   ```
   g++ bakery_game.cpp -o bakery_game
   ```

2. Run the compiled program:

   ```
   ./bakery_game
   ```

3. Follow the prompts and instructions displayed by the program to play the game.

### Note

- The program uses the `srand(time(0))` function to seed the random number generator. This ensures better randomness in the game.

- The program includes a `map` to store the items and their prices in euros. You can add or modify items and prices as needed.

- The program generates random variations in the customer's payment to add more diversity to the game.

- The program asks the player to input the correct change in the same format as the amount paid (euros and cents).

- The game loop allows you to serve multiple customers until you choose to exit.

Enjoy playing the Bakery Cashier Game!
