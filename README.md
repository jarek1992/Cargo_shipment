--CARGO SHIPMENT MANAGEMENT SYSTEM--

Overview:
Cargo Shipment is a C++ project designed to simulate playful ship cargo management. The program models various types of cargo, including fruits, alcohol, dry goods, weapons, and valuable items, each with unique properties such as price, quantity, and specific characteristics. Users can load cargo onto ships, transfer cargo between ships, unload cargo, and even simulate events such as fruit expiration. The program also models ships, keeping track of their cargo, crew members, and other relevant statistics.

Features:
- Ship Management: Create and manage ships with various capacities and crew sizes.
- Cargo Types: Manage multiple types of cargo such as fruits, dry fruits, alcohol, weapons, and more.
- Loading/Unloading: Load cargo onto ships, unload cargo from ships, and transfer cargo between ships.
- Expiration Simulation: Simulate the expiration process of perishable goods like fruits over time.
- Dry Fruit Special Mechanism: Dry fruits maintain value over time and deteriorate slower than regular fruits.
- Crew Management: Add or remove crew members from ships.
- Price and Value Management: Cargo items have different pricing and rarity levels, influencing their overall value.

Usage:
The program allows the user to:
1. Create ships with specific capacities and crew members.
2. Load various types of cargo onto ships.
3. Transfer cargo between different ships.
4. Unload cargo from ships.
5. Simulate perishable goods expiring over time.

The cargo includes several different classes:
- Fruit: Expires over a specific period.
- Dry Fruit: A subclass of Fruit with a special expiration system.
- Alcohol: Cargo with specific alcoholic content.
- Item: Valuables with different rarity levels.
- Weapon: Cargo with specified damage and rarity.

How to Build:
Prerequisites
- C++17 compiler
- CMake version 3.11 or higher

Building the Project:
1. Clone the repository: git clone https://github.com/yourusername/cargo_shipment.git
2. Navigate to the project directory: cd cargo_shipment
3. Create a build directory and run CMake: mkdir build && cd build && cmake ..
4. Compile the project: make
5. Run the program: ./cargo_management

