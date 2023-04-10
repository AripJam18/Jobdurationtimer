
Imports MySql.Data.MySqlClient
Module Koneksi
    Public CONN As MySqlConnection
    Public DA As MySqlDataAdapter
    Public DS As DataSet
    Public CMD As MySqlCommand
    Public DR As MySqlDataReader

    Public Sub ConnectSQL()
        Try
            CONN = New MySqlConnection("Server=localhost;" _
                                               + "user id=root;" _
                                               + "password=;" _
                                               + "database=arduino")
            If CONN.State = ConnectionState.Closed Then
                CONN.Open()
                MsgBox("Koneksi ke Database Berhasil")
            End If
        Catch ex As Exception
            MsgBox("konek Kedatabase Bermasalah")
        End Try
    End Sub
End Module

