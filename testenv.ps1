$env:APPDATA
[System.Environment]::SetEnvironmentVariable("APPDATA", "D:\a\_temp\foo", [System.EnvironmentVariableTarget]::Machine)
$env:APPDATA
[System.Environment]::SetEnvironmentVariable("APPDATA", "D:\a\_temp\foo", [System.EnvironmentVariableTarget]::User)
$env:APPDATA
