$lib_name = "rgb_stripe"
$doc_folder = [Environment]::GetFolderPath("MyDocuments")
$lib_folder = "$doc_folder\Arduino\libraries\$($lib_name)"


Remove-Item -Recurse $lib_folder -ErrorAction SilentlyContinue
Copy-Item -Recurse -Path ".\$($lib_name)" $lib_folder