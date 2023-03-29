
Imports System.Data.Odbc
Module Koneksi
    Public CONN As OdbcConnection
    Public DA As OdbcDataAdapter
    Public DS As DataSet
    Public CMD As OdbcCommand
    Public DR As OdbcDataReader

    Public Sub ConnectSQL()
        CONN = New OdbcConnection("dsn=KoneksiMySQL")
        CONN.Open()
    End Sub
End Module

