Imports System.Data.Odbc
Imports System.IO
Imports Excel = Microsoft.Office.Interop.Excel
Public Class Form1
    Dim lokasi As String = "D:\JobDuration\"
    Dim namafile As String

    Sub TampilGrid()
        DA = New OdbcDataAdapter("SELECT * FROM jobdurationtimer WHERE timestamp >= '" & Format(DTPFrom.Value, "yyyy-MM-dd") & "' AND timestamp >= '" & Format(DTPFrom.Value, "yyyy-MM-dd") & "' ", CONN)
        ''LIMIT 10 
        DS = New DataSet
        DA.Fill(DS)
        DGV.DataSource = DS.Tables(0)
        DGV.ReadOnly = True
    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles Me.Load
        ConnectSQL()
    End Sub

    Private Sub BtnTampil_Click(sender As Object, e As EventArgs) Handles BtnTampil.Click
        TampilGrid()
    End Sub

    Private Sub BtnExport_Click(sender As Object, e As EventArgs) Handles BtnExport.Click
        Dim xlApp As Excel.Application
        Dim xlWorkBook As Excel.Workbook
        Dim xlWorkSheet As Excel.Worksheet
        Dim misValue As Object = System.Reflection.Missing.Value

        Dim i As Int16, j As Int16

        xlApp = New Microsoft.Office.Interop.Excel.Application
        xlWorkBook = xlApp.Workbooks.Add(misValue)
        xlWorkSheet = xlWorkBook.Sheets("sheet1")

        For a = 0 To DGV.RowCount - 2
            For b = 0 To DGV.ColumnCount - 1
                For c As Integer = 1 To DGV.Columns.Count
                    xlWorkSheet.Cells(1, c) = DGV.Columns(c - 1).HeaderText
                    xlWorkSheet.Cells(a + 2, b + 1) = DGV(b, a).Value.ToString()
                Next
            Next
        Next

        If Directory.Exists(lokasi) = False Then
            Directory.CreateDirectory(lokasi)
        End If

        namafile = Format(Date.Today, "yyyy-MM-dd").ToString
        namafile = lokasi & namafile & ".xls"


        xlWorkBook.SaveAs(namafile, Excel.XlFileFormat.xlWorkbookNormal, misValue, misValue, misValue, misValue,
         Excel.XlSaveAsAccessMode.xlExclusive, misValue, misValue, misValue, misValue, misValue)
        xlWorkBook.Close(True, misValue, misValue)
        xlApp.Quit()

        releaseObject(xlWorkSheet)
        releaseObject(xlWorkBook)
        releaseObject(xlApp)

        MsgBox("Hasil export tersimpan di " & lokasi)

        If pesanTanya("Open File?") = True Then
            Process.Start(namafile)
        End If

    End Sub
    Private Sub releaseObject(ByVal obj As Object)
        Try
            System.Runtime.InteropServices.Marshal.ReleaseComObject(obj)
            obj = Nothing
        Catch ex As Exception
            obj = Nothing
        Finally
            GC.Collect()
        End Try
    End Sub
    Public Function pesanTanya(ByVal isiTanya As String, Optional ByVal yesbocancel As Boolean = False) As Object
        Dim strTanya As String

        If yesbocancel = False Then
            strTanya = MsgBox(isiTanya, vbQuestion + vbYesNo, "Question?")
            If strTanya = vbYes Then
                Return True
            Else
                Return False
            End If
        Else
            strTanya = MsgBox(isiTanya, vbQuestion + vbYesNoCancel, "Question?")
            If strTanya = vbYes Then
                Return vbYes
            ElseIf strTanya = vbNo Then
                Return vbNo
            Else
                Return vbCancel
            End If
        End If
    End Function
End Class
