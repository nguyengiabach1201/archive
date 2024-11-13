async function fetchRepoContent() {
    const owner = "your-username";
    const repo = "your-repository";
    const token = "your-personal-access-token";
    const url = `https://api.github.com/repos/${owner}/${repo}/contents/`;
    const options = { headers: { Authorization: `token ${token}` } };
    try {
        const response = await fetch(url, options);
        if (response.ok) {
            const files = await response.json();
            const fileList = document.getElementById("file-list");
            files.forEach((file) => {
                const listItem = document.createElement("li");
                const fileLink = document.createElement("a");
                fileLink.href = file.html_url;
                fileLink.textContent = file.name;
                listItem.appendChild(fileLink);
                fileList.appendChild(listItem);
            });
        } else {
            console.error(
                "Failed to fetch repository content:",
                response.statusText
            );
        }
    } catch (error) {
        console.error("Error fetching repository content:", error);
    }
}
fetchRepoContent();
