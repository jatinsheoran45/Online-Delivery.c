#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RESTAURANTS 5
#define MAX_MENU_ITEMS 10
#define MAX_USERS 10
typedef struct {
char name[50];
char menu[MAX_MENU_ITEMS][50];
float prices[MAX_MENU_ITEMS];
int menu_count;
} Restaurant;
typedef struct {
    typedef struct {
char username[50];
char password[50];
} User;
Restaurant restaurants[MAX_RESTAURANTS];
User users[MAX_USERS];
int user_count = 0;
int restaurant_count = 0;
void register_user() {
if (user_count >= MAX_USERS) {
printf("User limit reached!\n");
return;
}
printf("Enter username: ");
scanf("%s", users[user_count].username);
printf("Enter password: ");
scanf("%s", users[user_count].password);
user_count++;
printf("User registered successfully!\n");
}
void add_restaurant() {
if (restaurant_count >= MAX_RESTAURANTS) {
printf("Restaurant limit reached!\n");
return;
}
printf("Enter restaurant name: ");
scanf("%s", restaurants[restaurant_count].name);
printf("Enter number of menu items: ");
scanf("%d", &restaurants[restaurant_count].menu_count);
for (int i = 0; i < restaurants[restaurant_count].menu_count; i++) {
printf("Enter menu item name: ");
scanf("%s", restaurants[restaurant_count].menu[i]);
printf("Enter price: ");
scanf("%f", &restaurants[restaurant_count].prices[i]);
}
restaurant_count++;
printf("Restaurant added successfully!\n");
}
void view_restaurants() {
printf("Available Restaurants:\n");
for (int i = 0; i < restaurant_count; i++) {
printf("%d. %s\n", i + 1, restaurants[i].name);
for (int j = 0; j < restaurants[i].menu_count; j++) {
printf(" %s - $%.2f\n", restaurants[i].menu[j], restaurants[i].prices[j]);
}
}
}
void place_order() {
int rest_choice, item_choice;
printf("Select restaurant (1-%d): ", restaurant_count);
scanf("%d", &rest_choice);
if (rest_choice < 1 || rest_choice > restaurant_count) {
printf("Invalid restaurant selection!\n");
return;
}
printf("Select menu item (1-%d): ", restaurants[rest_choice - 1].menu_count);
scanf("%d", &item_choice);
if (item_choice < 1 || item_choice > restaurants[rest_choice - 1].menu_count) {
printf("Invalid menu item selection!\n");
return;
}
printf("Order placed for %s from %s. Total: $%.2f\n",
restaurants[rest_choice - 1].menu[item_choice - 1],
restaurants[rest_choice - 1].name,
restaurants[rest_choice - 1].prices[item_choice - 1]);
}
int main() {
int choice;
while (1) {
printf("\n1. Register User\n2. Add Restaurant\n3. View Restaurants\n4. Place Order\n5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
register_user();
break;
case 2:
add_restaurant();
break;
case 3:
view_restaurants();
break;
case 4:
place_order();
break;
case 5:
exit(0);
default:
printf("Invalid choice! Try again.\n");
}
}
return 0;
}