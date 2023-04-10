<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Dim DataGridViewCellStyle1 As System.Windows.Forms.DataGridViewCellStyle = New System.Windows.Forms.DataGridViewCellStyle()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Form1))
        Me.DGV = New System.Windows.Forms.DataGridView()
        Me.BtnTampil = New System.Windows.Forms.Button()
        Me.PanelButton = New System.Windows.Forms.Panel()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.BtnExport = New System.Windows.Forms.Button()
        Me.DTPFrom = New System.Windows.Forms.DateTimePicker()
        Me.DTPTo = New System.Windows.Forms.DateTimePicker()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.PanelData = New System.Windows.Forms.Panel()
        CType(Me.DGV, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.PanelButton.SuspendLayout()
        Me.GroupBox1.SuspendLayout()
        Me.PanelData.SuspendLayout()
        Me.SuspendLayout()
        '
        'DGV
        '
        Me.DGV.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.DGV.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize
        DataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft
        DataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.Window
        DataGridViewCellStyle1.Font = New System.Drawing.Font("Segoe UI Semibold", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        DataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.ControlText
        DataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Highlight
        DataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText
        DataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.[False]
        Me.DGV.DefaultCellStyle = DataGridViewCellStyle1
        Me.DGV.Dock = System.Windows.Forms.DockStyle.Fill
        Me.DGV.Location = New System.Drawing.Point(0, 0)
        Me.DGV.Name = "DGV"
        Me.DGV.Size = New System.Drawing.Size(535, 638)
        Me.DGV.TabIndex = 0
        '
        'BtnTampil
        '
        Me.BtnTampil.Image = CType(resources.GetObject("BtnTampil.Image"), System.Drawing.Image)
        Me.BtnTampil.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.BtnTampil.Location = New System.Drawing.Point(314, 18)
        Me.BtnTampil.Name = "BtnTampil"
        Me.BtnTampil.Size = New System.Drawing.Size(93, 35)
        Me.BtnTampil.TabIndex = 1
        Me.BtnTampil.Text = "Tampil"
        Me.BtnTampil.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        Me.BtnTampil.UseVisualStyleBackColor = True
        '
        'PanelButton
        '
        Me.PanelButton.Controls.Add(Me.GroupBox1)
        Me.PanelButton.Dock = System.Windows.Forms.DockStyle.Top
        Me.PanelButton.Location = New System.Drawing.Point(0, 0)
        Me.PanelButton.Name = "PanelButton"
        Me.PanelButton.Size = New System.Drawing.Size(535, 124)
        Me.PanelButton.TabIndex = 2
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.Label1)
        Me.GroupBox1.Controls.Add(Me.BtnExport)
        Me.GroupBox1.Controls.Add(Me.DTPFrom)
        Me.GroupBox1.Controls.Add(Me.BtnTampil)
        Me.GroupBox1.Controls.Add(Me.DTPTo)
        Me.GroupBox1.Controls.Add(Me.Label2)
        Me.GroupBox1.Font = New System.Drawing.Font("Segoe UI Semibold", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.GroupBox1.Location = New System.Drawing.Point(12, 12)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(517, 106)
        Me.GroupBox1.TabIndex = 7
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "Tanggal"
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(6, 29)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(32, 17)
        Me.Label1.TabIndex = 2
        Me.Label1.Text = "Dari"
        '
        'BtnExport
        '
        Me.BtnExport.Image = CType(resources.GetObject("BtnExport.Image"), System.Drawing.Image)
        Me.BtnExport.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.BtnExport.Location = New System.Drawing.Point(314, 63)
        Me.BtnExport.Name = "BtnExport"
        Me.BtnExport.Size = New System.Drawing.Size(93, 35)
        Me.BtnExport.TabIndex = 6
        Me.BtnExport.Text = "Export"
        Me.BtnExport.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        Me.BtnExport.UseVisualStyleBackColor = True
        '
        'DTPFrom
        '
        Me.DTPFrom.Location = New System.Drawing.Point(97, 24)
        Me.DTPFrom.Name = "DTPFrom"
        Me.DTPFrom.Size = New System.Drawing.Size(189, 25)
        Me.DTPFrom.TabIndex = 4
        '
        'DTPTo
        '
        Me.DTPTo.Location = New System.Drawing.Point(97, 65)
        Me.DTPTo.Name = "DTPTo"
        Me.DTPTo.Size = New System.Drawing.Size(186, 25)
        Me.DTPTo.TabIndex = 5
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(6, 65)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(50, 17)
        Me.Label2.TabIndex = 3
        Me.Label2.Text = "hingga"
        '
        'PanelData
        '
        Me.PanelData.Controls.Add(Me.DGV)
        Me.PanelData.Dock = System.Windows.Forms.DockStyle.Fill
        Me.PanelData.Location = New System.Drawing.Point(0, 124)
        Me.PanelData.Name = "PanelData"
        Me.PanelData.Size = New System.Drawing.Size(535, 638)
        Me.PanelData.TabIndex = 3
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(535, 762)
        Me.Controls.Add(Me.PanelData)
        Me.Controls.Add(Me.PanelButton)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.Name = "Form1"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "Job Duration Timer [MySQLClient]"
        CType(Me.DGV, System.ComponentModel.ISupportInitialize).EndInit()
        Me.PanelButton.ResumeLayout(False)
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox1.PerformLayout()
        Me.PanelData.ResumeLayout(False)
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents DGV As DataGridView
    Friend WithEvents BtnTampil As Button
    Friend WithEvents PanelButton As Panel
    Friend WithEvents GroupBox1 As GroupBox
    Friend WithEvents Label1 As Label
    Friend WithEvents DTPFrom As DateTimePicker
    Friend WithEvents DTPTo As DateTimePicker
    Friend WithEvents Label2 As Label
    Friend WithEvents BtnExport As Button
    Friend WithEvents PanelData As Panel
End Class
