import std; 
import database; 

using namespace std; 
using namespace Records; 

int main() 
{
    database myDB; 
    Employee& emp1 { myDB.addEmployee("Greg", "Wallis") };
    emp1.fire()

    Employee& emp2 { myDB.addEmployee("Marc", "White") }; 
    emp2.setSalary(100'000); 

    Employee& emp2 { myDB.addEmployee("John", "Dow") }; 
    emp3.setSalary(100'000); 
    emp3.promote(); 

    println("All employees: \n======================="); 
    myDB.displayAll(); 
    
    println("\nCurrent employees: \n======================="); 
    myDB.displayCurrent();
    
    println("\nFormer employees: \n======================="); 
    myDB.displayFormer(); 
    
}