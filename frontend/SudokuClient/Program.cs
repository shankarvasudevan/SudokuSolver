using System;
using System.Text;
using System.Net.Sockets;

namespace SudokuClient
{
    class Program
    {
        private const int Port = 9999;
        private const string HostName = "localhost";

        static void Main(string[] args)
        {
            using (var client = new TcpClient(HostName, Port))
            {
                if (!client.Connected)
                {
                    Console.WriteLine("Could not connect");
                    return;
                }

                using (NetworkStream stream = client.GetStream())
                {
                    Byte[] data = System.Text.Encoding.ASCII.GetBytes("Hello server");
                    stream.Write(data, 0, data.Length);
                    stream.Close();
                }

                client.Close();
            }

            Console.WriteLine("Press ENTER to continue");
            Console.Read();
        }
    }
}
