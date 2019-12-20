const { app, BrowserWindow } = require('electron')

const fs = require('fs')

const root = fs.readdirSync('/')

let win

function createWindow () {
    win = new BrowserWindow({
        width: 800,
        height:600,
        webPreferences: {
            nodeIntegration: true
        }
    })

    win.loadFile('index.html')
    
    // win.webContents.openDevTools()
    
    win.on('closed', () => {
        win = null
    })
}

app.on('ready', createWindow)
// app.on('ready', console.log(root))

app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') {
        app.quit()
    }
})

app.on('activate', () => {
    if (win === null) {
        createWindow()
    }
})