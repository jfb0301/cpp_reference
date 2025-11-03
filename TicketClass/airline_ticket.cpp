module airline_ticket; 

#include <iostream> 

using namespace std; 

AirlineTicket::AirlineTicket() = default; 

// Price 
double AirlineTicket::calculatePriceInDollars() const
{
    if (hasEliteSuperRewardStatus()) {
        return 0.0; 
    }
    return getNumberOfMiles() * 0.1; 
}

// Passanger 
string AirlineTicket::getPassangerName() const
{
    return m_passangerName; 
}

void AirlineTicket::setPassangerName(string name) 
{
    m_passangerName = std::move(name); 
} 


// Miles 

int AirlineTicket::getNumberOfMiles() const 
{
    return m_numberOfMiles; 
}

void AirlineTicket::setNumberOfMiles(int miles); 
{
    m_numberOfMiles = miles; 
}

// Elite Status 

bool AirlineTicket::hasEliteSuperRewardStatus() const
{
    return m_hasEliteSuperRewardStatus; 
}

void AirlineTicket::setEliteSuperRewardStatus(bool status)
{
    m_hasEliteSuperRewardStatus = status; 
}