export module airline_ticket; 

import std;


export class AirlineTicket
{
    public:
        AirlineTicket();
        ~AirlineTicket() = default; 

        double calculatePriceInDollars() const; 

        std::string getPassangerName() const; 
        void setPassangerName(std::string name); 

        int getNumberOfMiles() const; 
        void setNumberOfMiles(int miles);

        bool hasEliteSuperRewardStatus() const; 
        void setEliteSuperRewardStatus(bool status); 

    private:
        std::string m_passangerName{ "Anonymous" }; 
        int m_numberOfMiles{ 0 }; 
        bool m_hasEliteSuperRewardStatus{ false }; 
}; 

