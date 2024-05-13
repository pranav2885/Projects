import mysql.connector

# Connect to MySQL server
def connect_to_mysql():
    try:
        conn = mysql.connector.connect(
            host="localhost", 
            user="root",  
            password="your_password",  
            database="hotel_database"  
        )
        print("Connected to MySQL!")
        return conn
    except mysql.connector.Error as err:
        print(f"Error: {err}")


# Function to execute a given stored procedure
def execute_stored_procedure(conn, procedure_name, *args):
    try:
        cursor = conn.cursor()
        cursor.callproc(procedure_name, args)
        for result in cursor.stored_results():
            print(result.fetchall())
        cursor.close()
    except mysql.connector.Error as err:
        print(f"Error: {err}")

# Main function to provide user interface
def main():
    conn = connect_to_mysql()
    while True:
        print("\nMenu:")
        print("1. Get details of guests by month")
        print("2. Get total bookings by guest and year")
        print("3. Get total rooms booked by hotel and date")
        print("4. Get unique countries with hotels")
        print("5. Get hotels with URLs")
        print("6. Get available rooms in hotel\n")
        print("7. Exit")
        choice = input("Enter your choice (1-7): ")
        if choice == '1':
            month = input("Enter the month (e.g., 1 for January): ")
            execute_stored_procedure(conn, "GetGuestsByMonth", int(month))
        elif choice == '2':
            guest_id = input("Enter the guest ID: ")
            year = input("Enter the year: ")
            execute_stored_procedure(conn, "GetTotalBookingsByGuestAndYear", int(guest_id), int(year))
        elif choice == '3':
            hotel_id = input("Enter the hotel ID: ")
            date = input("Enter the date (YYYY-MM-DD): ")
            execute_stored_procedure(conn, "GetTotalRoomsBookedByHotelAndDate", int(hotel_id), date)
        elif choice == '4':
            execute_stored_procedure(conn, "GetUniqueCountriesWithHotels")
        elif choice == '5':
            execute_stored_procedure(conn, "GetHotelsWithURL")
        elif choice == '6':
            hotel_id = input("Enter the hotel ID: ")
            date = input("Enter the date (YYYY-MM-DD): ")
            execute_stored_procedure(conn, "GetAvailableRoomsInHotel", int(hotel_id), date)
        elif choice == '7':
            break
        else:
            print("Invalid choice! Please enter a number between 1 and 7.")

    # Close the connection
    conn.close()
    print("Connection to MySQL closed.")

if __name__ == "__main__":
    main()
