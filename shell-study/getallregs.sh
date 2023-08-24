#!/bin/bash

# Set the GitHub username
USERNAME="work-design"

# Make a GET request to the GitHub API to retrieve the user's repositories
repositories=$(curl -s "https://api.github.com/users/$USERNAME/repos")

# Iterate over the repositories and clone each one
for row in $(echo "${repositories}" | jq -r '.[] | @base64'); do
    _jq() {
     echo ${row} | base64 --decode | jq -r ${1}
    }
    repo_name=$(_jq '.name')
    repo_url=$(_jq '.clone_url')
    git clone $repo_url
done