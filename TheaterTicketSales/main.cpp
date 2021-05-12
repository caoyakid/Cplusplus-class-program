#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int NUM_ROWS = 15,
          ROW_SIZE = 30;

class TicketManager
{
private:
    struct SeatStructure
    {
        char status; // '#':available; '*':sold
        double price;

        SeatStructure()
        { //Default constructor
            status = '#';
            price = 0.0;
        }
    };
    SeatStructure seat[NUM_ROWS][ROW_SIZE];

    int seatsSold;
    double totalRevenue;

    void printTickets(int, int, int);

public:
    TicketManager();
    ~TicketManager();
    void displaySeats();
    bool requestTickets(int, int, int);
    double purchaseTickets(int, int, int);
    void displaySalesReport();
};
// -----------------TicketManager Class Function Implementation-----------------
TicketManager::TicketManager()
{
    double rowPrice;
    ifstream availFile, priceFile;
    availFile.open("SeatAvailability.dat"); //open the data files for input
    priceFile.open("SeatPrices.dat");

    seatsSold = 0;
    totalRevenue = 0.0;

    for (int row = 0; row < NUM_ROWS; row++)
    {
        // Read in the price for this row
        priceFile >> rowPrice;

        // For each seat in the row
        for (int col = 0; col < ROW_SIZE; col++)
        {
            availFile >> seat[row][col].status;
            seat[row][col].price = rowPrice;
            // If seat has been sold, add to seatsSold and totalRevenue
            if (seat[row][col].status == '*')
            {
                seatsSold++;
                totalRevenue += rowPrice;
            }
        }
    }
    // Close the files
    availFile.close();
    priceFile.close();
}

TicketManager::~TicketManager()
{
    ofstream availFile;

    // Open the "avail" data file for output
    availFile.open("SeatAvailability.dat");

    // Write each seat's status (available or taken) out to the file
    for (int row = 0; row < NUM_ROWS; row++)
    {
        for (int col = 0; col < ROW_SIZE; col++)
        {
            availFile << seat[row][col].status;
        }
        availFile << endl;
    }
    availFile.close();
}

// displaySeats : display a chart showing sold and available seats
void TicketManager::displaySeats()
{
    // display the diagram title
    cout << "\n                   Seats"
         << "\n        123456789012345678901234567890\n";

    // display the grid of seats
    for (int row = 0; row < NUM_ROWS; row++)
    {
        cout << "\nRow " << setw(2) << row + 1 << "\t";
        for (int col = 0; col < ROW_SIZE; col++)
        {
            cout << seat[row][col].status;
        }
    }

    // display the legend
    cout << "\n\n\n\tLegend\t* = Sold";
    cout << "\n\t\t# = Available";

    // hold the screen until the user is ready to return
    cout << "\n\n\nPress the Enter key to continue.";
    cin.ignore();
    cin.get();
}

// requesetTickets : returns true or false to indicate if requested seats exist
bool TicketManager::requestTickets(int numSeatsRequested, int requestedRow, int startSeat)
{
    // array rows and columns begin with 0, rather than 1
    int row = requestedRow - 1,
        firstSeat = startSeat - 1,
        lastSeat = firstSeat + numSeatsRequested - 1;

    double pricePerSeat;

    if (row < 0 || row >= NUM_ROWS)
    {
        cout << "\nIllegal row request. Rows are numbered 1 - " << NUM_ROWS << ".\n\n";
        return false;
    }

    if (firstSeat < 0 || lastSeat >= ROW_SIZE)
    {
        cout << "\nOne or more of the seats you have requested do not exist. \n"
             << "Seats in each row are number 1 - " << ROW_SIZE << ".\n\n";
        return false;
    }

    for (int seatWanted = firstSeat; seatWanted <= lastSeat; seatWanted++)
    {
        if (seat[row][seatWanted].status == '*')
        {
            cout << "\nOne or more of the seats you have requested are already sold.\n";
            return false;
        }
    }

    // If we got this far all requested seats exist and are available for purchase.
    pricePerSeat = seat[row][firstSeat].price;
    cout << "\nThe seats you have requested are available for purchase.\n";
    cout << "The total purchase price is " << numSeatsRequested << " * $" << pricePerSeat
         << " = $ " << (numSeatsRequested * pricePerSeat) << endl
         << endl;
    return true;
}

// purchaseTickets : handle ticket purchases for a previously validated ticket request.
double TicketManager::purchaseTickets(int numSeats, int requestedRow, int startSeat)
{
    int row = requestedRow - 1,
        firstSeat = startSeat - 1,
        lastSeat = firstSeat + numSeats - 1;

    double pricePerSeat = seat[row][firstSeat].price;
    double totalPrice = pricePerSeat * numSeats;
    double amtPaid, changeDue;

    // collect money
    cout << "The price for the requested tickets is $ " << totalPrice << endl
         << "Please input amount paid: $";
    cin >> amtPaid;

    if (amtPaid >= totalPrice) // if payment is sufficient, sell the tickets
    {
        // mark these seats taken
        for (int purchase = firstSeat; purchase <= lastSeat; purchase++)
        {
            seat[row][purchase].status = '*';
        }
        // add to seats sold and revenue accumulators
        seatsSold += numSeats;
        totalRevenue += numSeats * pricePerSeat;

        // call printTickets to print the actual tickets
        // starting row and seat numbering from 1 (not 0)
        printTickets(requestedRow, firstSeat + 1, lastSeat + 1);

        // display a purchase summary for the patron
        changeDue = amtPaid - totalPrice;
        cout << "\n\nTicket purchased : " << numSeats << endl
             << "Payment              : $" << setw(6) << amtPaid << endl
             << "Total ticket price   : $" << setw(6) << totalPrice << endl
             << "Change due           : $" << setw(6) << changeDue << endl
             << endl;
    }
    else
    {
        cout << "Insufficient payment. \n"
             << "The sale has been cancelled and your money is being returned.\n\n";
        changeDue = amtPaid;
    }
    return changeDue;
}

// printTickets : print one ticket for each seat sold.
void TicketManager::printTickets(int rowNum, int firstSeatNum, int lastSeatNum)
{
    double seatPrice = seat[rowNum - 1][firstSeatNum - 1].price;

    for (int ticket = firstSeatNum; ticket <= lastSeatNum; ticket++)
    {
        cout << "\n\n\n****************************************\n"
             << "*         Little Theater Production          *\n"
             << "*         Row " << setw(2) << rowNum << "  Seat " << setw(2) << ticket
             << "                   *\n"
             << "*         Price: " << setw(5) << seatPrice
             << "                   *\n"
             << "****************************************\n";
    }
}

// displaySaleReport : display sales information
void TicketManager::displaySalesReport()
{
    cout << "\n\nLittle Theater Sales Report\n"
         << "_______________________________\n\n"
         << "Seats sold:                    " << seatsSold << endl
         << "Seats available:               " << NUM_ROWS * ROW_SIZE - seatsSold << endl
         << "Total revenue to data:       $ " << totalRevenue << "\n\n\n";
    cout << "Press the Enter key to continue.";
    cin.ignore();
    cin.get();
}

// -----------------Client Program-----------------

// Function prototypes
void displayMenu();
int getChoice(int);
void getUserRequest(int &, int &, int &); // reference is necessary

const int MAX_MENU_CHOICE = 4;
int main()
{
    TicketManager boxOffice;

    int choice, numSeats, row, startSeat;
    bool ticketRequestOK;
    char buy;

    // set print formats
    cout << fixed << showpoint << setprecision(2);

    do
    {
        displayMenu();
        choice = getChoice(MAX_MENU_CHOICE);

        switch (choice)
        {
        case 1:
            boxOffice.displaySeats();
            break;
        case 2:
            getUserRequest(numSeats, row, startSeat); // Client module to get user input
            ticketRequestOK = boxOffice.requestTickets(numSeats, row, startSeat);
            if (ticketRequestOK)
            {
                cout << "Do you wish to purchase these tickets (Y/N)? ";
                cin >> buy;
                if (toupper(buy) == 'Y')
                    boxOffice.purchaseTickets(numSeats, row, startSeat);
            }
            break;
        case 3:
            boxOffice.displaySalesReport();
            break;
        default: // do nothing
            break;
        } // end switch
    } while (choice != MAX_MENU_CHOICE);

    return 0;
}

// This func: display the menu of program options
void displayMenu()
{
    // Display menu of choices
    cout << "\n\n\n\t\tWelcome to Y's Theater" << endl
         << endl;
    cout << "\n\t1. View Available Seats";
    cout << "\n\t2. Request Tickets";
    cout << "\n\t3. Display Theater Sales Report";
    cout << "\n\t4. Exit the Program\n";
}

// This func: accepts, validate and returns the user choice
int getChoice(int max)
{
    int choice;

    // Get and validate user's choice
    cin >> choice;
    while (choice < 1 || choice > max)
    {
        cout << "Your choice must be among 1 ~ " << max << "! Please re-enter: ";
        cin >> choice;
    }
    return choice;
}

// This func: accepts, validate, and returns user's seat selection
void getUserRequest(int &numSeats, int &row, int &startSeat)
{
    cout << "Number of seats desired (1-30): ";
    numSeats = getChoice(30);

    cout << "Desired row (1-15): ";
    row = getChoice(15);

    cout << "Desired starting seat number in the row (1-30): ";
    startSeat = getChoice(30);
}
