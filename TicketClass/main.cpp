// main.cpp
import airline_ticket;

#include <iostream> 

int main()
{
    AirlineTicket ticket;
    ticket.setPassengerName("Alice");
    ticket.setNumberOfMiles(1500);
    ticket.setEliteSuperRewardsStatus(false);

    cout << ticket.getPassengerName() << " flies for $"
         << ticket.calculatePriceInDollars() << '\n';

    // Elite member
    ticket.setEliteSuperRewardsStatus(true);
    cout << "Elite price: $" << ticket.calculatePriceInDollars() << '\n';
}