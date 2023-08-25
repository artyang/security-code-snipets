using System.Data.SqlClient;

namespace SqlConnectionExample
{
    class Program
    {
        static void Main(string[] args)
        {
            string serverName = "your_server_name";
            string databaseName = "your_database_name";
            string username = "your_username";
            string password = "your_password";

            SqlConnectionStringBuilder builder = new SqlConnectionStringBuilder();
            builder.DataSource = serverName;
            builder.InitialCatalog = databaseName;
            builder.UserID = username;
            builder.Password = password;
            builder.Encrypt = true; // Use encryption (TLS)
            builder.TrustServerCertificate = false; // Set to true to bypass server certificate validation (not recommended for production)

            string connectionString = builder.ToString();

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("Connection opened successfully.");
                    // Perform database operations here
                }
                catch (Exception ex)
                {
                    Console.WriteLine("Error: " + ex.Message);
                }
            }
        }
    }
}
In the above example, replace the placeholders (your_server_name, your_database_name, your_username, your_password) with your actual server information and credentials. The Encrypt property is set to true to enable TLS encryption, which secures the communication between your application and the SQL Server. The TrustServerCertificate property is set to false to ensure that the server certificate is validated. However, in a production environment, you should provide a valid server certificate and set TrustServerCertificate to false.

Remember that handling sensitive information like passwords in your code is not recommended. In a real-world scenario, you should use secure methods for storing and retrieving connection strings and credentials, such as environment variables or a configuration management system.
