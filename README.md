# Archive

Each item in this repository is identified by an **8-character code** with the format **YYMMDDXY**.

### Code Breakdown

-   **YYMMDD**: This represents the date the item was archived (**YY** = year, **MM** = month, **DD** = day).

-   **X**: This single character indicates the **file type**.

| Character | File extension |  Description  |
| :-------: | :------------: | :-----------: |
|     A     |      .png      |  Image file   |
|     B     |      .jpg      |  Image file   |
|     C     |     .jpeg      |  Image file   |
|     D     |      .gif      |  Image file   |
|     E     |      .mp4      |  Video file   |
|     F     |      .mp3      |  Audio file   |
|     G     |      .wav      |  Audio file   |
|     H     |      .avi      |  Video file   |
|     I     |      .mov      |  Video file   |
|     J     |      .zip      | Archive file  |
|     K     |      .rar      | Archive file  |
|     L     |      .pdf      | Document file |
|     M     |      .txt      | Document file |
|     N     |      .rtf      | Document file |
|     O     |      .csv      | Document file |
|     P     |      .doc      | Document file |
|     Q     |     .docx      | Document file |
|     R     |      .xls      | Document file |
|     S     |     .xlsx      | Document file |
|     T     |      .ppt      | Document file |
|     U     |     .pptx      | Document file |
|     V     |      .htm      | Document file |
|     W     |     .html      | Document file |

-   **Y**: This single character is a sequential identifier for files archived on the same day. For example, the first file archived would be `A`, the second would be `B`, and so on.

### Example

A file named `240312BL.jpg` would have the following meaning:

-   **240312**: Archived on March 12, 2024.
-   **B**: The file type is `.jpg` (as shown in the table).
-   **L**: It's the 12th file of any type archived on that day.

> [!NOTE]
> The file extension on the filename itself is for convenience, but the code is the official identifier.

## Accessing a file via indirect URL

To access a file, simply navigate to the following URL format, replacing the code with your file's unique identifier:
`https://nguyengiabach.com/archive/YYMMDDXY`

### Example

To access `240312BL.jpg`, use the URL `https://nguyengiabach.com/archive/240312BL`.

### Accessing a file via direct URL

You can access a file by typing its full path directly into your browser's address bar. This is the recommended method for linking to any media.

> [!WARNING]
> When embedding an image, video, or other media file in HTML, you must always provide the full, correct path to the file. The short 8-character code alone will not work.

### Example

```html
<img
    src="http://nguyengiabach1201.github.io/archive/images/250821BA.jpg"
    alt="The Longma at Quoc Hoc's trấn phong"
/>
```

## Folder Structure

Files are organized by type into the following subdirectories:

-   `/archive/images/`
-   `/archive/videos/`
-   `/archive/audios/`
-   `/archive/documents/`
-   `/archive/archives/`
